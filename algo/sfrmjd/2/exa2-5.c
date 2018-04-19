#include <stdio.h>
#include <limits.h>


/* 输入 一些 整数， 求出 它们 的 最小值、 最大值 和平 均值（ 保留 3 位 小数）。 */


int main(int argc, char **argv)
{
        float avg, count = 0.0;
        int a, min = INT_MAX, max = INT_MIN, sum = 0;
        while (scanf("%d", &a) == 1) {
                printf("a = %d\n", a);
                if (a < min) min = a;
                if (a > max) max = a;
                sum += a;
                count++;
        }
        avg = sum / count;
        printf("%d %d %.3lf\n", min, max, avg);
        return 0;
}
