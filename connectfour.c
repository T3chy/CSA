#include<stdio.h>
#include <stdlib.h>
int** initalize() {
  int* values = calloc(5*6, sizeof(int)); // calloc = allocates first arg number of second arg sized memory block
  int** rows = malloc(6*sizeof(int*)); // malloc =
  for (int i=0; i<6;i++){
    rows[i] = values + i*5;
  }
  return rows;
}



int main(){
  int ** rows = initalize();
  printf("gamer time \n");
  for (int i=0; i < sizeof(rows); i++){
      for (int j=0; j <sizeof(rows[0]); j++) {
        printf("%d ",rows[i][j]);
      }
      printf("\n");
  }
  return 0;
}