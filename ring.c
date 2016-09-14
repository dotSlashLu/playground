#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ring.h"

ringp ring_init(int size)
{
        ringp ring = calloc(sizeof(Ring), 1);
        void *buffer = calloc(size, 1);
        ring->size = size;
        ring->first = ring->curr = buffer;
        return ring;
}


short ring_destroy(ringp r)
{
        free(r->first);
        free(r);
        return 1;
}

void *ring_put(ringp r, const void *content, int size)
{
        /* boundary check */
        int overflow = size - (r->size - (r->curr - r->first));
        int of;
        /*
         * this can be hugely optimized by calculating and applying
         * the final state directly
         * */
        while (1) {
                of = overflow;
                // no overflow
                if (of <= 0) {
                        strncpy(r->curr, content, size);
                        if (overflow == 0)
                                return r->curr = r->first;
                        return r->curr += size + 1;
                }

                if (of > r->size)
                        of = r->size;
                size_t rest = size - of;
                strncpy(r->curr, content, rest);
                strncpy(r->first, content + rest, of);
                if (overflow <= r->size)
                        return r->curr = r->first + of;
                else
                        overflow -= r->size;
        }
}

void ring_clear(ringp r)
{
        memset(r->first, 0, r->size);
        r->curr = r->first;
}

int main(int argc, char **argv)
{
        ringp r = ring_init(10);
        printf("ring: %p, size: %d, fisrt: %p\n",
                        r, r->size, r->first);
        const char *str = "1234567890123";
        int i;
        for (i = 0; i < 10; i++) {
                ring_put(r, str, strlen(str) + 1);
                printf("buffer: %s, curr: %p\n", (char *)r->first, r->curr);
        }
        ring_clear(r);
        printf("buffer: %s, curr: %p\n", (char *)r->first, r->curr);
        ring_destroy(r);
        return 0;
}
