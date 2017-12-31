#include <stdio.h>
#include <stdlib.h>

void unique_string(char *iStr);

/* Sequentially parses the passed in string and returns if atleast one character is
*  duplicate. For example, string 'hello' has character 'l' twice
*/

void unique_string(char *iStr)
{
    int i = 0, j = 0;

    while (*iStr != '\0') {
        j=i+1;
        while (*(iStr+j) != '\0') {
            if (*(iStr+i) == *(iStr+j)) {
                printf("The string is not unique\n");
                return;
            }
            j++;
        }
        i++;
    }
    printf("The string is unique\n");
}

main()
{
    char input_string[16];

    printf("Enter the string\n");
    scanf("%s", input_string);
    printf("%s\n", input_string);

    unique_string(input_string);
}


