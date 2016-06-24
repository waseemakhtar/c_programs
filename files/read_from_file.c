/* Read the contents of the file and copy it in the local array.
   Contents of the file are expected to be numbers and they are
   on per line
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str[70], temp_str[70];
    FILE *p; //pointer used to count the number of contents
    FILE *tmp;//pointer used to store the number in array
    int numelm = 0; //number of elements in the file
    
    //Make sure you create this file
    if((tmp=fopen("/tmp/string.txt","r"))==NULL)
    {
        printf("\nUnable to open file string.txt\n");
        return 0;
    }

    if((p=fopen("/tmp/string.txt","r"))==NULL)
    {
        printf("\nUnable to open file string.txt\n");
        return 0;
    }

    while(fgets(str,sizeof(str),p)!=NULL) {
        numelm++;
    }
    printf("Number of elements read from the file: %d\n", numelm); 

    int listofintf[numelm];
    int i = 0;

    while(fgets(temp_str,sizeof(temp_str),tmp)!=NULL) {
        listofintf[i] = atoi(temp_str);
        i++;
    }

    printf("Entries read from the file and in array are:\n");
    for (i=0; i < numelm; i++)
    {
        printf("%d\n", listofintf[i]);
    }

    fclose(tmp);
    fclose(p);
    return 0;
}
