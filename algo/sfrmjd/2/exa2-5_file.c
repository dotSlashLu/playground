#include <stdio.h>
#include <limits.h>


/* 输入 一些 整数， 求出 它们 的 最小值、 最大值 和平 均值（ 保留 3 位 小数）。 */


int main(int argc, char **argv)
{
        FILE *in = fopen("exa2-5.in", "rb"), *out = fopen("exa2-5.out", "wb");
        if (!in) {
                perror("fopen");
                return 1;
        }
        float avg, count = 0.0;
        int a, min = INT_MAX, max = INT_MIN, sum = 0;
        while (fscanf(in, "%d", &a) == 1) {
                // printf(in, "a = %d\n", a);
                if (a < min) min = a;
                if (a > max) max = a;
                sum += a;
                count++;
        }
        avg = sum / count;
        fprintf(out, "%d %d %.3lf\n", min, max, avg);
        fclose(in);
        fclose(out);
        return 0;
}
