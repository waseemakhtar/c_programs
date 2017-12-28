/*
 * Find G.C.D
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main ()
{
    int x=200, y=184, rem, temp;

    if (x>y) {
        temp = x;
        x = y;
        y = temp;
    }

    printf("GCD of %d and %d is:", x, y);
    while (x<y) {
        rem = y % x;
        if (rem == 0)
            break;
        y = x;
        x = rem;
    }

    printf("%d\n", x);
}
