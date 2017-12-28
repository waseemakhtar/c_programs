// Reverse the string in its place

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int swap_char(char *str1, char *str2)
{
    char tmp;

    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;

    return;
}

int main()
{
    char string[] = "Hello World";
    int len, i = 0;
    char *str = string;

    len = strlen(string);

   printf("Reverse of the string: %s is ", str);
    while(1) { 
        swap_char(&string[i], &string[len-1]);
        i++; len--;
        if ( i >= len) break;
    }
    printf("%s\n", str);
}
