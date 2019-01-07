#include <stdio.h>
#include <time.h>
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_CYAN    "\x1b[36m"    // Color will be Cyan
#define ANSI_COLOR_RESET   "\x1b[0m"    //  Will RESET color
#define ANSI_COLOR_BLUE    "\x1b[34m"     // Color will be Blue
#define ANSI_COLOR_MAGENTA "\x1b[35m"    // Color will be Magenta

/**
#define ANSI_COLOR_RED     "\x1b[31m"     Color will be Red
#define ANSI_COLOR_YELLOW  "\x1b[33m"     Color will be Yellow
*/



// swaps 2 element ocne this function is called
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//Sets last element as a pivot. CORRECTLY places pivot in correct sorted spot
//Places all items lower to the left of the pivot, and all items higher to the right of the pivot

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j = low;

    for (j; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//QuickSort method in which is called by the main method
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Prints sorted Array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);

}

// Driver program to test above functions
int main()
{
    int n;
    printf("Array Size: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    int i;
    for(i=0; i<n;i++)
      arr[i] = rand()%100;

    printf("" ANSI_COLOR_BLUE "");
    printf("\nUnsorted Array: ");
    printArray(arr, n);
    printf("" ANSI_COLOR_RESET "");
    quickSort(arr, 0, n-1);
    printf("\n\n");
    printf("" ANSI_COLOR_MAGENTA "");
    printf("Sorted array: ");
    printArray(arr, n);
    printf("" ANSI_COLOR_RESET "");
    printf("\n\n" ANSI_COLOR_GREEN   "---PROGRAM SUCCESSFUL---" "\n");
    return 0;
}
