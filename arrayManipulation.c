#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int n, m;
    int maxNum;
    int i;

    scanf("%d", &n);
    scanf("%d", &m);

    int *arrayN = (int *)malloc(n * sizeof(int));
    int *arrayA = (int *)malloc(m * sizeof(int));
    int *arrayB = (int *)malloc(m * sizeof(int));
    int *arrayK = (int *)malloc(m * sizeof(int));

    int j = n - 1;
    for(i = 0; i < n; i++){
      arrayN[i] = 0;
      printf("%d", arrayN[i]);
      if(i != j){
        printf(", ");
      }
    }

    printf("\n");

    for(i = 0; i < m; i++){
      scanf("%d", &arrayA[i]);
      scanf("%d", &arrayB[i]);
      scanf("%d", &arrayK[i]);
    }









    printf("\n");


  maxNum = 10;
  printf("\n%d", maxNum);

  free(arrayN);
  free(arrayA);
  free(arrayB);
  free(arrayK);

  return 0;
}
