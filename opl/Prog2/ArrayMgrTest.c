#include <stdio.h>
#include <stdlib.h>
#include "ArrayMgr.h"

	/*	==========================================================	*
	 *																*
	 *			You may modify this test program if desired			*
	 *	   but I will test your program with MY ORIGINAL files!!	*
	 *																*
	 *	==========================================================	*/

/*
 *	File:			ArrayMgrTest.c
 *	Project:		ArrayMgr
 *	Assignment:		Program #2
 *	Author:			Mr. Rich Brozovic
 *	Date:			4/10/2017
 *	Modified by:	--->  Your Name  <---  if modified
 *	Date Modified:	--->  Your Date  <---  if modified
 *	University:		McMurry University
 *	Course:			COSC-4310, OPL
 *	Semester:		Spring 2017
 *	Instructor:		Mr. Brozovic
 *	Language:		C (Visual Studio 2015)
 *	Description:	Implement and test both FORTRAN and C pointer-style
 *					array mapping functions
 */

/* define lower- and upper-bounds for desired 4-dim array	*/
/*		similar to data[3][2][4][5]							*/
#define LBs -1
#define UBs 1
#define LBd 2
#define UBd 3
#define LBr -2
#define UBr 1
#define LBc 3
#define UBc 7

void ArrayMgrTest(void)
{
	struct ArrayDescriptor_t *CADptr = (struct ArrayDescriptor_t *) malloc(sizeof(struct ArrayDescriptor_t));
	struct ArrayDescriptor_t *FADptr = (struct ArrayDescriptor_t *) malloc(sizeof(struct ArrayDescriptor_t));
	void *CBAptr, *FBAptr;	/* hold base addresses for convenience */
    int s, d, r, c;			/* indexes */

	if ( !CADptr || !FADptr ) {
		printf("\tUnable to allocate both array descriptors!!\n");
		printf("\t-- PLEASE CONTACT Mr. B!\nPROGRAM IS ABORTING . . .\n");
		abort();
	}

	printf("  For the purpose of this program\n");
    printf("    1st dim is # of sections - each section is a \"cube\"\n");
    printf("    2nd dim is # of layers (depth) of a \"cube\"\n");
    printf("    3rd dim is # of rows of a \"table\"\n");
    printf("    4th dim is # of cols of a \"table\"\n\n");
    printf("  Size of elements = %d bytes\n\n",sizeof(int));
    printf("  Each array element (data) will print as a quadruple (s,d,r,c)\n");
    printf("    which is it's set of index values\n");
    printf("  Each array will be displayed by section and layer, ");
	printf("one row or col at a time\n");
    printf("    First using MY mapping function from ArrayMgr.lib\n");
    printf("    Second using YOUR array mapping function\n\n");
    printf("  If your functions work properly, ");
    printf("each pair of output lines will be identical!\n\n");

	/* build array descriptor for C pointer-style array */
	CADptr->name = "CData";
	CADptr->BaseAddress = 0;	/* provided by "Fill" function */
	CADptr->nbr_dim = 4;		/* set < 4 to test error detection */
	CADptr->DimArray =
		(struct Dimension_t*)calloc(CADptr->nbr_dim,sizeof(struct Dimension_t));
	if ( !CADptr->DimArray ) {
		printf("\tUnable to allocate DimArray for C array descriptor!!\n");
		printf("\t-- PLEASE CONTACT Mr. B!\nPROGRAM IS ABORTING . . .\n");
		abort();
	}
	CADptr->DimArray[0].lowerbound = LBs;
	CADptr->DimArray[0].upperbound = UBs;
	CADptr->DimArray[1].lowerbound = LBd;
	CADptr->DimArray[1].upperbound = UBd;
	CADptr->DimArray[2].lowerbound = LBr;
	CADptr->DimArray[2].upperbound = UBr;
	CADptr->DimArray[3].lowerbound = LBc;
	CADptr->DimArray[3].upperbound = UBc;

	/* build array descriptor for FORTRAN-style array */
	FADptr->name = "FData";
	FADptr->BaseAddress = 0;	/* provided by "Fill" function */
	FADptr->nbr_dim = 4;		/* set < 4 to test error detection */
	FADptr->DimArray =
		(struct Dimension_t*)calloc(FADptr->nbr_dim,sizeof(struct Dimension_t));
	if ( !FADptr->DimArray ) {
		printf("\tUnable to allocate DimArray for FORTRAN array descriptor!!\n");
		printf("\t-- PLEASE CONTACT Mr. B!\nPROGRAM IS ABORTING . . .\n");
		abort();
	}
	FADptr->DimArray[0].lowerbound = LBs;
	FADptr->DimArray[0].upperbound = UBs;
	FADptr->DimArray[1].lowerbound = LBd;
	FADptr->DimArray[1].upperbound = UBd;
	FADptr->DimArray[2].lowerbound = LBr;
	FADptr->DimArray[2].upperbound = UBr;
	FADptr->DimArray[3].lowerbound = LBc;
	FADptr->DimArray[3].upperbound = UBc;

    /* Fill the arrays with data */
	FillArrays(CADptr, FADptr);
	CBAptr = CADptr->BaseAddress;  /* convenience */
	FBAptr = FADptr->BaseAddress;  /* convenience */
	if (!CBAptr) {
		printf("\tUnable to allocate both array descriptors!!\n");
		printf("\t-- PLEASE CONTACT Mr. B!\nPROGRAM IS ABORTING . . .\n");
		abort();
	}

	/* arrays are filled with data -- let's print contents */
	/* printed by sections showing each layer */

	/* C pointer-style array */
	if (debug) {
		printf("\nC pointer-style Array Descriptor:\n");
		printAD(CADptr);
	}
	printf("\nC pointer-style Array data contents for comparison\n");
    for ( s = LBs; s <= UBs; s++ ) {
        for ( d = LBd; d <= UBd; d++ ) {
			printf("\nSect/Layer [%d][%d]\n", s, d);
			for ( r = LBr; r <= UBr; r++ ) {
				/* ArrayMgr.lib mapping function */
				printf("Row [%2d]\t", r);
				for ( c = LBc; c <= UBc; c++ ) {
					printCell(*(int*)_C_MAP(CADptr,s,d,r,c));
					printf("  ");
				}
				printf("\n");
				/* Your mapping function */
				printf("Row [%2d]\t", r);
				for ( c = LBc; c <= UBc; c++ ) {
					printCell(*(int*)carray(CADptr,s,d,r,c));
					printf("  ");
				}
				printf("\n");
			} /* end of row */
		} /* end of layer */
	} /* end of section */
    printf("\nEnd of C pointer-style array\n\n");

	/* FORTRAN-style array */
	if (debug) {
		printf("\nFORTRAN-style Array Descriptor:\n");
		printAD(FADptr);
	}
	printf("\nFORTRAN-style Array data contents for comparison\n");
    for ( s = LBs; s <= UBs; s++ ) {
        for ( d = LBd; d <= UBd; d++ ) {
			printf("\nSect/Layer [%d][%d]\n", s, d);
			for ( c = LBc; c <= UBc; c++ ) {
				/* ArrayMgr.lib mapping function */
				printf("Col [%2d]\t", c);
				for ( r = LBr; r <= UBr; r++ ) {
					printCell(*(int*)_F_MAP(FADptr,s,d,r,c));
					printf("  ");
				}
				printf("\n");
				/* Your mapping function */
				printf("Col [%2d]\t", c);
				for ( r = LBr; r <= UBr; r++ ) {
					printCell(*(int*)farray(FADptr,s,d,r,c));
					printf("  ");
					//printf("  %p ", FADptr->BaseAddress);
				}
				printf("\n");
			} /* end of row */
		} /* end of layer */
	} /* end of section */
    printf("\nEnd of FORTRAN-style array\n\n");

//	CADptr = NULL;
//	CADptr->BaseAddress = NULL;
//	CADptr->DimArray = NULL;
//	CADptr->nbr_dim = 5;
//	FADptr = NULL;
//	FADptr->BaseAddress = NULL;
//	FADptr->DimArray = NULL;
//	FADptr->nbr_dim = 5;
//	FADptr->BaseAddress = NULL;
//	printCell(*(int*)carray(CADptr,0,0,0,0));
//	printCell(*(int*)farray(FADptr,0,0,0,0));

	return;
}
