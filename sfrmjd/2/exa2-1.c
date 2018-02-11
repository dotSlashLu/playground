#include <math.h>
#include <stdio.h>
#include <string.h>


/* 输出 所有 形如 aabb 的 4 位 完全 平方 数 */


int ispow(int n)
{
    int m = floor(sqrt(n) + 0.5);
    if (m * m == n)
        return 1;
    return 0;
}


void sqrtmethod()
{
    // all aabb
    int a, b;
    for (a = 1; a <= 9; a++) {
        for (b = 0; b <= 9; b++) {
            int n = a * 1100 + b * 11;
            if (ispow(n))
                printf("%d\n", n);
        }
    }
}


/* this method avoids the loss of pricision in float calc */
void enummethod()
{
    int a;
    for (a = 1; ; a++) {
        int b = a * a;
        if (b < 1111)
            continue;
        else if (b > 9999)
            break;
        int k = b / 1000, h = b / 100 % 10;
        if (k != h)
            continue;
        int t = b / 10 % 10, u = b % 10;
        if (t != u)
            continue;
        printf("%d\n", b);
    }
}


int main(int argc, char const *argv[])
{
    enummethod();
    return 0;
}