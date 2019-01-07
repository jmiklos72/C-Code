/**
Sort using qsort() in c
As fast, if not, faster than quick sort algorithm
Calls qsort() from stdlib header file
Uses time for random seed for array of random numbers
Using colors to differentiate between Unsorted or Sorted array
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRN   "\x1b[32m"
#define CYN    "\x1b[36m"
#define BLU    "\x1b[34m"
#define MAG    "\x1b[35m"
#define RESET   "\x1b[0m"

int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
int main(int argc, char* argv[])
{
    int n, i, max;

    printf("Please enter Array Size: ");
    scanf("%d", &n);
    printf("\nPlease enter the Max number inside Array: ");
    scanf("%d", &max);
    int x[n];

    srand(time(NULL));
    printf("" BLU "\nUnsorted Array: " RESET "\n");
    printf("" MAG "");

    for(i=0;i<n;i++){
      x[i] = rand()%max;
      printf("%d ", x[i]);
      if(i%20 == 0 && i != 0){
        printf("\n");
      }
    }

    printf("" RESET "");
    printf("" BLU "\n\nSorted Array: " RESET "\n");

    qsort (x, n, sizeof(*x), comp);

    for (i=0; i < n ; i++){
        printf ("" CYN "%d " RESET "", x[i]);
        if(i%20 == 0 && i != 0){
          printf("\n");
        }
      }

    printf("\n\n---------- " GRN "PROGRAM COMPLETE"  RESET  " ----------\n");

    return 0;
}
