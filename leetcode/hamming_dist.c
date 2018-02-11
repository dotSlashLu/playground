#include <stdio.h>
#include <stdlib.h>

int hammingWeight(int x);

int hammingDistance(int x, int y) {
        // return __builtin_popcount(x ^ y);
        return hammingWeight(x ^ y);
}

int hammingWeight(int x) {
        size_t ones = 0;
        while (x) {
                if (!(x % 2)) {
                        x = x >> 1;
                        continue;
                }
                else
                        ones += 1;
                x = x >> 1;
        }

        return ones;
}

int main(int argc, char **argv)
{
        int x = atoi(*++argv),
            y = atoi(*++argv);
        printf("hamming distance of %d and %d is %d\n",
               x, y, hammingDistance(x, y));
        return 0;
}
