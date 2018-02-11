#include <stdio.h>
#include <math.h>


/* 1-1 */
void avg()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    double avg = (a + b + c) / 3.0;
    printf("%.3lf\n", avg);
}


/* 1-2 */
void temp()
{
    int f;
    scanf("%d", &f);
    printf("%.3lf\n", 5 * (f - 32) / 9.0);
}


/* 1-3 */
void sum()
{
    int a;
    scanf("%d", &a);
    int sum = ((1 + a) * a) / 2;
    printf("%d\n", sum);
}


/* 1-4 */
void sc()
{
    int a;
    scanf("%d", &a);
    const float PI = acos(-1);
    float rad = a * PI / 180.0;
    printf("%f %f\n", sin(rad), cos(rad));
}


/* 1-5 */
void discount()
{
    const float price = 95.0, p = 0.85, thresh = 300;
    int n;
    scanf("%d", &n);
    if (n <= thresh / price) {
        printf("%.2lf\n", n * price);
        return;
    }

    float ret = price * p * n;
    printf("%.2lf\n", ret);
}


/* 1-6 */
void triangle()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b < c || a + c < b || b + c < a) {
        printf("not a triangle\n");
    }
    else if (pow(a, 2) + pow(b, 2) == pow(c, 2) ||
        pow(a, 2) + pow(c, 2) == pow(b, 2) ||
        pow(b, 2) + pow(c, 2) == pow(a, 2)) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
}


/* 1-7 */
void year()
{
    int y;
    scanf("%d", &y);
    if ((!(y % 400)) || (!(y % 4) && (y % 100))) {
        printf("yes\n");
    }
    else
        printf("no\n");
}


/* 1-8 */
int main(int argc, char const *argv[])
{
    // avg();
    // temp();
    // sum();
    // sc();
    // discount();
    // triangle();
    year();
    return 0;
}
