/*
https://leetcode.com/problems/hamming-distance/description/
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define uint_32 unsigned int
uint_32 HammingDistance(uint_32 a, uint_32 b);
int main()
{
  uint_32 a, b;
  printf("Welcome to the Hamming Distance program.\n"
        "Enter two numbers: \n");
  scanf("%d", &a);
  scanf("%d", &b);
  printf("Hamming distance of %ld and %ld is %ld", 
    a, b, HammingDistance(a, b));
  return 0;
}

uint_32 HammingDistance(uint_32 a, uint_32 b){
  unsigned int i = 0, hd = 0;
  bool x, y;

  while (i < 32) {
      x = (a >> i) & 1;
      y = (b >> i) & 1;

      if (x != y)
          hd++;

      i++;
    }
    return hd;
}
