//Rick Nygaard
//Program 1
//COSC 1325
//Dr. Watson

#include <stdio.h>

int main (void) {
  
  int y[3][2][2]={{{1,2},{3,4}},
				  {{5,6}, {7,8}},
				  {{9,10},{11,12}}};
  int i,j,k;
  
  for (i=0;i<3;i++){
	  printf("Layer %d\n",i);
	  for(j=0;j<2;j++){// print the address and value of 3d array
		for(k=0;k<2;k++){
			printf("Address %d = Value %d \n", *(((y+i)+j)+k),*(*(*(y+i)+j)+k));
		}
	  }
	  printf("\n");
  }
  

  
  return 0;
}