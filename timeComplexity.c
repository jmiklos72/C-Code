#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(){
  clock_t t;
  t = clock();
    int num, i, j, mod, div, p;


    scanf("%d", &num);
    int arr[num];
    int n[num];

    for(i=0;i<num;i++){
        scanf("%d", &arr[i]);
    }

    for(i=0;i<num;i++){
        p = arr[i];
        div = p/2;
         j = 2;
        do{
        if(p>3 && p%2 == 0){
            n[i] = 1;
            break;
        }
            mod = p%j;
        if(mod == 0){
            n[i] = 1;

            break;
        }
        else if(mod != 0){
            n[i] = 0;
            }
      j++;

        }while(j<=div);
    }

    for(i=0;i<num;i++){
        if(arr[i] == 2){
            n[i] = 0;
        }
        if(arr[i] == 1){
            n[i] = 1;
        }
        if(n[i] == 1){
            printf("Not prime\n");
        }
        if(n[i] == 0){
            printf("Prime\n");
        }
    }
    t = clock() - t;
    double timeTaken = ((double)t)/CLOCKS_PER_SEC;


    printf("\nExecution Time: %f seconds\n", timeTaken);
return 0;
}
