#include <stdio.h>
#include <time.h>


/* PI / 4 = 1 - 1/3 + 1/5 - 1/7 ... until the last term < 1e-6 */


int main(int argc, char const *argv[])
{
    double sum = 0;
    int i = 0;
    while (1) {
        double n = 1.0 / (i * 2 + 1);
        if (i % 2 == 0) sum += n;
        else sum -= n;
        if (n < 1e-6) break;
        i++;
    }
    printf("%.6lf\n", sum);
    printf("time used: %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}