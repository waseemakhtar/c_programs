#include <stdio.h>

/* Find median of the numbers as they are inputted */
int main()
{
        int m1, m2, tot_num=0;
        float median;
        int values[10];

        while (tot_num < 10) {
            scanf("%d", &values[tot_num]);
            tot_num++;
            if (tot_num == 1) {
                printf("Median is %d, for total numbers = %d\n",
                        values[tot_num-1], tot_num);
                continue;
            }
            if (tot_num % 2 == 0) { //even
                m1 = values[(tot_num/2) - 1];
                m2 = values[tot_num/2];
                median = (float) (m1+m2)/2;
            } else { //odd
                median = (tot_num == 1)? values[0]: (values[tot_num/2]);
            }
            printf("Median is %f, for total numbers = %d\n",
                    median, tot_num);
        }
}
