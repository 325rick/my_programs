//Rick Nygaard
//Program 1
//COSC 1325
//Dr. Watson

#include <stdio.h>

int main (void) {
  
  int y[][2]={{1,2},{3,4},{5,6}}; 
  int i,j;
  
  for (i=0;i<3;i++){
	  for(j=0;j<2;j++){// print the address and value of 2d array
		  printf("Address %d = Value %d "  , *((y+i)+j),*(*(y+i)+j));
	  }
	  printf("\n");
  }
  

  
  return 0;
}