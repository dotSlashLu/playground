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
        // boundary check
        int overflow = size - (r->size - (r->curr - r->first));
        printf("overflow: %d, overwrite\n", overflow);

        // no overflow
        if (overflow <= 0) {
                strncpy(r->curr + 1, content, size);
                if (overflow == 0)
                        return r->curr = r->first;
                return r->curr += size;
        }

        strncpy(r->curr + 1, content, size - overflow);
        strncpy(r->first, content, overflow);
        return r->curr = r->first + overflow;
}

int main(int argc, char **argv)
{
        ringp r = ring_init(10);
        printf("ring: %p, size: %d, fisrt: %p\n",
                        r, r->size, r->first);
        const char *str = "1234567";
        ring_put(r, str, strlen(str) + 1);
        printf("put: %s, curr: %p\n", (char *)r->first, r->curr);
        ring_destroy(r);
        return 0;
}
