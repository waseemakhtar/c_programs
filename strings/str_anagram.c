/* Given two strings, check if they are anagrams
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_anagram(char *str1, char *str2);
bool check_anagram(char *str1, char *str2)
{
  int total1 = 0, total2 = 0;
  while((*str1 != '\0') && 
      (*str2 != '\0')) { 
      total1 += (int)*str1;
      total2 += (int)*str2;
      str1++; str2++;
  }

  if (total1 == total2) return true;
  else return false;
}

int main()
{
  char string1[32];
  char string2[32];
  char *str1 = string1;
  char *str2 = string2;

  printf("Enter first string without spaces - limit to 31 characters: \n");
  scanf("%s", string1);
  printf("Enter second string without spaces - limit to 31 characters: \n");
  scanf("%s", string2);

  if (strlen(string1) != strlen(string2))
      printf("Strings are not anagrams\n");
  else if (check_anagram(str1, str2) == true)
      printf("Strings are anagrams\n");
  else 
      printf("Strings are not anagrams\n");
}
