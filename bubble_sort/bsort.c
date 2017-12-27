/* Use bubble-sort technique to sort the given list in ascending order
*/
#include<stdio.h>
#include<stdlib.h>

void bb_sort(int *ptr, int arr_size);
void swap(int *a, int *b);

/* Use two array indices(i,j) and traverse the array comparing values
   at respective indices and swapping the values if value at array indices 
   i is greater than j
*/
void swap(int *a, int *b)
{
   int tmp;

   tmp = *a; 
   *a = *b; 
   *b = tmp; 

   return;
}

/* Use two array indices(i,j) and traverse the array comparing values
   at respective indices and swapping the values if value at array indices 
   i is greater than j
*/
void bb_sort(int *ptr, int arr_size)
{
    int i,j;

    for (i = 0; i < arr_size; i++) {
        for (j = i+1; j < arr_size; j++) {
            if(ptr[i] > ptr[j]) {
                swap(ptr+i, ptr+j);
            }
        }
    }
    return;
}

int main()
{
    int unsorted[] = {13,14,15,16,22,3,4,5};
    int i, arr_size;

    arr_size = sizeof(unsorted)/sizeof(unsorted[0]); 

    if(arr_size == 1) {
        printf("Given array is already sorted\n");
        exit(0);
    }

    bb_sort(unsorted, arr_size);

    printf("\nThe sorted array is:\n");
    for (i = 0; i < arr_size; i++) 
        printf("%d ", unsorted[i]);
    printf("\n");

    exit(0);
}
