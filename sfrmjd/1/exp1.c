#include <stdio.h>
#include <math.h>

/*
int 和 double 并不能 保存 任意 的 整数 和 浮点 数。 它们 究竟 有着 怎样 的 限制 呢？
*/
int main(int argc, char const *argv[])
{
    /* int */
    int a1 = 11111, a2 = 111111, a3 = 111111111;
    printf("5 ones: %d, 6 ones: %d, 9 ones: %d\n", a1 * a1, a2 * a2, a3 * a3);

    /* float */
    float b1 = 11111, b2 = 111111, b3 = 111111111;
    printf("5 ones float: %lf, 6 ones float: %lf, 9 ones float: %lf\n", 
        b1 * b1, b2 * b2, b3 * b3);

    /* sqrt(-10) 
        sqrt(-10) = -nan
    */
    printf("sqrt(-10) = %lf\n", sqrt(-10));

    /* float devision by zero 
        1.0 / 0.0 = inf 
        0.0 / 0.0 = -nan
    */
    printf("1.0 / 0.0 = %f 0.0 / 0.0 = %f\n", 1.0 / 0.0, 0.0 / 0.0);

    return 0;
}