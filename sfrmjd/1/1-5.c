#include <stdio.h>

/* 输入 3 个 整数， 从小到大 排序 后 输出。*/

int main(int argc, char const *argv[])
{
    int a, b, c, t;
    scanf("%d%d%d", &a, &b, &c);
    // if a > b, exchange a and b
    if (a > b) {
        t = a; a = b; b = t;
    }
    // if a > c, exchange a and c
    if (a > c) {
        t = a; a = c; c = t;
    }
    // if b > c, exchange b and c
    if (b > c) {
        t = b; b = c; c = t;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}