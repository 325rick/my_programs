#ifndef A_MGR
#define A_MGR

	/*	==========================================================	*
	 *			--->   WARNING -- WARNING -- WARNING   <---			*
	 *																*
	 *					 DO NOT MODIFY THIS FILE!					*
	 *																*
	 *		I will test your program with MY ORIGINAL files!!		*
	 *																*
	 *	SPECIAL INSTRUCTIONS:										*
	 *	Copy the file "ArrayMgr.lib" from the program assignment	*
	 *	zip file into your VS project folder and enter its file		*
	 *	name into the "Additional Dependencies" property under		*
	 *	configuration-linker-input.									*
	 *																*
	 *		--->	The comments in this file contain	<---		*
	 *		--->		IMPORTANT documentation!!		<---		*
	 *																*
	 *	==========================================================	*/

/*
 *	File:			ArrayMgr.h
 *	Project:		ArrayMgr
 *	Assignment:		Program #2
 *	Author:			Mr. Rich Brozovic
 *	Date:			4/10/2017
 *	University:		McMurry University
 *	Course:			COSC-4310, OPL
 *	Semester:		Spring 2017
 *	Instructor:		Mr. Brozovic
 *	Language:		C (Visual Studio 2015)
 *	Description:	Implement and test both C pointer-style and
 *					FORTRAN-style array mapping functions
 *
 *	ASSUMPTIONS:
 *	===========
 *
 *	1)	The items lbs, ubs, lbd, ubd, lbr, ubr, lbc, and ubc
 *		used in the following sample declarations are
 *		actually integer literals (positive or negative)
 *
 *	2)	FORTRAN 90 array declaration:
 *			INTEGER FDATA(lbr:ubr, lbc:ubc, lbd:ubd, lbs:ubs)
 *		could be
 *			INTEGER FDATA(1:3, 0:4, 2:7, -1:2)
 *		which would have 3 sections, 5 layers, 6 rows, and 4 cols
 *		with 3 * 5 * 6 * 4 = 360 elements
 *
 *	3)	A language that implements arrays to support jagged arrays
 *		might allow the following style array declaration:
 *			int CDATA[lbr:ubr][lbc:ubc][lbd:ubd][lbs:ubs];
 *		could be
 *			int CDATA[-1:4][1:3][0:3][-10:-4];
 *		which would have 6 sections, 3 layers, 4 rows, and 7 cols
 *		with 6 * 3 * 4 * 7 = 504 elements
 *
 *	REQUIREMENT:
 *	===========
 *
 *	Your array access functions must accept an array descriptor (via a
 *	constant pointer) and four pass-by-value integers (index values) and
 *	return a pointer to the array element referenced by the four index values.
 *	The following are example assignment statements for a 4-dim array:
 *
 *	for FORTRAN 90:
 *		==========
 *		INTEGER R, C, D, S, V
 *		FDATA(S,D,R,C) = v
 *      V = FDATA(S,D,R,C)
 *
 *	for C/C++:
 *		=====
 *		int r, c, d, s, v;
 *		CDATA[s][d][r][c] = v;
 *      v = CDATA[s][d][r][c]
 *
 *	Your access functions must return a pointer to the desired element.
 *	Following function calls are substitutes for the above array references.
 *
 *		*farray(&farray_desc,s,d,r,c) = v;
 *		v = *farray(&farray_desc,s,d,r,c);
 *
 *		*carray(&carray_desc,s,d,r,c) = v;
 *		v = *carray(&carray_desc,s,d,r,c);
 *
 *	To simplify this programming assignment, the arrays will have 4 dimensions
 *	and you can code your access functions based on that knowledge.  However,
 *	since you are not building the array descriptors, your access functions
 *	must use "safe" programming practices by checking for the correct number
 *	of dimensions and non-null pointers.  You functions must abort if any
 *	errors are detected.
 */

/*	======================================================================	*
 *																			*
 *		GLOBAL DECLARATIONS -- for convenience & debugging support			*
 *																			*
 *	======================================================================	*/

#define Boolean int
#define TRUE 1
#define FALSE 0

	/*	Following flag switched "on" by main
		when 't' found as command line program argument */
	extern Boolean debug;

/*	======================================================================	*
 *																			*
 *		TYPE DECLARATIONS													*
 *																			*
 *		Array descriptor and elements of the dimensions array within		*
 *		the array descriptor containing	the lower- and upper-bounds of		*
 *		each dimension														*
 *																			*
 *	======================================================================	*/

	typedef struct Dimension_t {
		/* index types assumed to be standard int for this assignment */
		int lowerbound;
		int upperbound;
	} Dimension_t;

	typedef struct ArrayDescriptor_t {
		char *name;						/* mainly for debugging purposes		*/
		/* elementtype */				/* element type assumed to be int		*/
		unsigned short int nbr_dim;		/* should be > 0						*/
		struct Dimension_t *DimArray;	/* dynamic array with nbr_dim elements	*/
		void *BaseAddress;				/* void allows elements of any type		*/
	} ArrayDescriptor_t;

/*	======================================================================	*
 *																			*
 *		Prototypes for the two array access functions						*
 *																			*
 *		--->	YOU MUST implement in ArrayMgr.c	<---					*
 *																			*
 *		ints are section, layer, row, and col index values					*
 *																			*
 *	=======================================================================	*/

	int *carray(const struct ArrayDescriptor_t*, int, int, int, int);
	int *farray(const struct ArrayDescriptor_t*, int, int, int, int);

/*	======================================================================	*
 *																			*
 *		"Test" function called by main -- code included in zip file			*
 *			-- add source code file to your project							*
 *																			*
 *	======================================================================	*/

	void ArrayMgrTest(void);

/*	======================================================================	*
 *																			*
 *		The remaining functions are needed by the "TEST" function and are	*
 *		provided via ArrayMgr.lib -- you will NOT be provided with the		*
 *		source code!														*
 *																			*
 *	======================================================================	*
 *																			*
 *				Functions to work with array elements						*
 *																			*
 *	Elements of the arrays used for this assignment are actually standard	*
 *	integers but the following functions "pack" and "unpack" and print the	*
 *	individual 0-based index values of the 4 dimensions for an individual	*
 *	element into the 4 bytes of a standard int.								*
 *																			*
 *	For example:															*
 *		array element DATA[1][2][3][4], with all lower-bounds of 0, would	*
 *		would contain Sect = 1, Layer = 2, Row = 3, and Col = 4 which		*
 *		are "packed" into a single integer in hex form x01020304 but with	*
 *		lower-bounds of [-1][1][-2][2], respectively, the "adjusted"		*
 *		0-based index values would be [2][1][5][2] and the resulting		*
 *		"packed" value would be x02010502									*
 *																			*
 *	======================================================================	*
 *																			*
 *	Functions to "pack" four index values into a standard int and			*
 *	to print content of a single array element as (s,d,r,c)					*
 *																			*
 *	======================================================================	*/

	int indx2int(int indx1, int indx2, int indx3, int indx4);
	void printCell(int data);

/*	======================================================================	*
 *																			*
 *		Function prints information from a single array descriptor			*
 *																			*
 *	======================================================================	*/

	void printAD(const struct ArrayDescriptor_t*);

/*	======================================================================	*
 *																			*
 *			The remaining functions are for --> MY USE ONLY!! <--			*
 *																			*
 *		"Fill" function loads arrays with data -- called by "Test"			*
 *		"MAPping" array access functions -- produces correct array			*
 *			indexing to print correct results to compare your results		*
 *																			*
 *	======================================================================	*/

	void FillArrays(struct ArrayDescriptor_t*, struct ArrayDescriptor_t*);
	void *_C_MAP(const struct ArrayDescriptor_t*, int, int, int, int);
	void *_F_MAP(const struct ArrayDescriptor_t*, int, int, int, int);

#endif
