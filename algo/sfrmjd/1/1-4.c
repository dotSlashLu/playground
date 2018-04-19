#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nhead, nfoot;
    scanf("%d%d", &nhead, &nfoot);
    // r = m/2 - n
    // c = n - m/2 + n
      // = 2n - m/2
    if (nfoot % 2) {
        printf("No answer\n");
        return 0;
    }
    int c = 2 * nhead - nfoot / 2;
    if (c < 0 || c > nhead) {
        printf("No answer\n");
        return 0;
    }
    printf("%d %d\n", c, nfoot / 2 - nhead);
    return 0;
}