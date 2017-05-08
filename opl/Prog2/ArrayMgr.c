#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ArrayMgr.h"

	/*	======================	*
	 *							*
	 *		---> YOU <---		*
	 *							*
	 *		Must implement		*
	 *		the following		*
	 *	  mapping functions!	*
	 *							*
	 *	======================	*/

/*
 *	File:			ArrayMgr.c
 *	Project:		ArrayMgr
 *	Assignment:		Program #2
 *	Author:			Mr. Rich Brozovic
 *	Date:			4/10/2017
 *	Modified by:	--->  Rick Nygaard  <---  because you must modify code
 *	Date Modified:	--->  5/06/17  <---  because you must modify code
 *	University:		McMurry University
 *	Course:			COSC-4310, OPL
 *	Semester:		Spring 2017
 *	Instructor:		Mr. Brozovic
 *	Language:		C (Visual Studio 2015)
 *	Description:	Implement both FORTRAN and C pointer-style
 *					array mapping functions
 */

/*	======================================================================	*
 *																			*
 *					C pointer-style array mapping function					*
 *																			*
 *	======================================================================	*/

int *carray(const struct ArrayDescriptor_t *ADptr,
	int index1, int index2, int index3, int index4)
{
	/* following is a place holder only
		-- you MUST replace the call to MY mapping function with YOUR code */

	int lbs = ADptr->DimArray[0].lowerbound;
	int ubs = ADptr->DimArray[0].upperbound;
	int lbd = ADptr->DimArray[1].lowerbound;
	int ubd = ADptr->DimArray[1].upperbound;
	int lbr = ADptr->DimArray[2].lowerbound;
	int ubr = ADptr->DimArray[2].upperbound;
	int lbc = ADptr->DimArray[3].lowerbound;
	int ubc = ADptr->DimArray[3].upperbound;

	assert(lbs <= index1 && ubs >= index1);
	assert(lbd <= index2 && ubd >= index2);
	assert(lbr <= index3 && ubr >= index3);
	assert(lbc <= index4 && ubc >= index4);

	int ****base = (int****)ADptr->BaseAddress;
	
	int * rowaddr = (base[index1 - lbs][index2-lbd][index3-lbr]+index4-lbc);
	return (int*)rowaddr;
	
}	

/*	======================================================================	*
 *																			*
 *					FORTRAN-style array mapping function					*
 *																			*
 *	======================================================================	*/

int *farray(const struct ArrayDescriptor_t *ADptr,
			int index1, int index2, int index3, int index4)
{
	/* following is a place holder only
		-- you MUST replace the call to MY mapping function with YOUR code */

	int lbs = ADptr->DimArray[0].lowerbound;
	int ubs = ADptr->DimArray[0].upperbound;
	int lbd = ADptr->DimArray[1].lowerbound;
	int ubd = ADptr->DimArray[1].upperbound;
	int lbr = ADptr->DimArray[2].lowerbound;
	int ubr = ADptr->DimArray[2].upperbound;
	int lbc = ADptr->DimArray[3].lowerbound;
	int ubc = ADptr->DimArray[3].upperbound;

	//out of bounds testing
	assert(lbs <= index1 && ubs >= index1);
	assert(lbd <= index2 && ubd >= index2);
	assert(lbr <= index3 && ubr >= index3);
	assert(lbc <= index4 && ubc >= index4);
	
	//size of arrays
	int depdim = (ubd-lbd) + 1;
	int rowdim = (ubr-lbr) + 1;
	int coldim = (ubc-lbc) + 1;
	int element = sizeof(int);
	int layer = rowdim * coldim;
	int sect = layer * depdim;

	int myaddr = ((int)ADptr->BaseAddress + element * (sect*(index1 - lbs) + layer*(index2 - lbd) + (index3 - lbr) + rowdim * (index4 - lbc)));
	
	return (int*)myaddr;	
}
