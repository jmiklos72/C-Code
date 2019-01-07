#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n, m, i, j;
    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++){
      scanf("%d", &arr[i]);
    }

    scanf("%d", &m);
    int que[m];

    for(i=0;i<m;i++){
      scanf("%d", &que[i]);
    }

    //take size of queries, check for exclusive ors of EACH element in arr[n]

    int a, b, xor[m], x=0;
    for(i=0;i<m;i++){
      a = que[i];
      xor[i] = 0;
        for(j=0;j<n;j++){
          b = arr[j];
          x = a ^ b;
          if(x > xor[i]){
            xor[i] = x;
          }
          else{

          }
        }
    }

for(i=0;i<m;i++){
  printf("%d\n", xor[i]);
}

return 0;
}
