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

/* Use two array indices(i,j) and traverse the array comparing adjacent values
   at respective indices and swapping the values if value at array indices 
   i is greater than j. Continue this until the array is sorted.
*/
void bb_sort(int *ptr, int arr_size)
{
    int i,j, swapped;

    do {
        swapped = 0;
        for (i = 0; i < arr_size-1; i++) {
            j = i+1;
            if(ptr[i] > ptr[j]) {
                swapped = 1; //Set if one more iteration is required
                swap(ptr+i, ptr+j);
            }
        }
    } while (swapped > 0);

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
