/* Find minimum number in a sorted array which is rotated
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int rot_arr[] = {13,14,15,16,22,3,4,5};
    int mid, i = 0, j;

    j = sizeof(rot_arr)/sizeof(rot_arr[0]) - 1; 
    mid = (j-i)/2-1;

    if (j == 1) //If there is only one number in the given array
        printf("Minimum number is %d\n", rot_arr[j-1]);

    //Employ binary search scheme to find minimum number
    while (1) {
        if(rot_arr[mid] > rot_arr[j]) {
            i = mid; 
            mid += (j-i)/2; 
        } else if(rot_arr[mid] < rot_arr[mid-1]) {
            printf("Minimum number of the list is %d\n", rot_arr[mid]);
            break;
        } else {
            j = mid;
            mid = (j-i)/2;
        }
    }
}
