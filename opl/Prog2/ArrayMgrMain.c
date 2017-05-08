#include <stdio.h>
#include "ArrayMgr.h"

	/*	==================================================	*
	 *	   --->   WARNING -- WARNING -- WARNING   <---		*
	 *														*
	 *				DO NOT MODIFY THIS FILE!				*
	 *														*
	 *   I will test your program with MY ORIGINAL files!!	*
	 *	==================================================	*/

/*
 *	File:			ArrayMgrMain.c
 *	Project:		ArrayMgr
 *	Assignment:		Program #2
 *	Author:			Mr. Rich Brozovic
 *	Date:			4/10/2017
 *	University:		McMurry University
 *	Course:			COSC-4310, OPL
 *	Semester:		Spring 2017
 *	Instructor:		Mr. Brozovic
 *	Language:		C (Visual Studio 2015)
 *	Description:	Implement and test both FORTRAN and C pointer-style
 *					array mapping functions
 */
 
/**************************************************************************
 *	To run the program with extra debugging output:
 *		right-click your VS project in the solution explorer pane
 *		select properties from the shortcut menu
 *		select Debugging under Configuration Properties in the left pane
 *		enter "t" (no quotes) for "Command Arguments" in the right pane
 *
 *	Use the same process to remove the "t" to disable extra output
 *
 *  To send program output directly to a text file
 *     place " >filename.txt" after the "t" on the command line (no quotes)
 *
 *	Use the global boolean variable "debug" with if statements to control
 *	extra debugging output from your code.  When run without the "debug"
 *	turned on, the only output allowed is from main and ArrayMgrTest.
 *
 *************************************************************************/

/* Global variable matches up with "extern" declarations in other files */
Boolean debug;

int main(int argc, char* argv[])
{
    printf("\a\n\t\tArray Mapping Functions Program\n");
    printf("\t\t      by Mr Rich Brozovic\n");
    printf("\t\t      McMurry  University\n");
    printf("\t\t     COSC-4310 Spring 2017\n\n");
    debug = ( argc > 1 && *(argv[1]) == 't' );
	printf("  Calling ArrayMgrTest() with debug = %s ...\n\n",
			(debug)?"TRUE":"FALSE");
	ArrayMgrTest();
	printf("\a");
	return 0;
}
