#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ring.h"

ringp ring_init(ringp r, int size)
{
        void *buffer = calloc(size, 1);
        r->size = size;
        r->head = r->curr = buffer;
        r->tail = r->head + size;
        return r;
}


short ring_destroy(ringp r)
{
        /* invalid next size on debian... */
        free(r->head);
        free(r);
        return 1;
}

void *ring_put(ringp r, const void *content, int size)
{
        /* boundary check */
        /* problem: can we ensure tail is behind curr? */
        int overflow = size - (r->tail - r->curr);
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
                                return r->curr = r->head;
                        return r->curr += size + 1;
                }

                if (of > r->size)
                        of = r->size;
                size_t rest = size - of;
                strncpy(r->curr, content, rest);
                strncpy(r->head, content + rest, of);
                if (overflow <= r->size)
                        return r->curr = r->head + of;
                else
                        overflow -= r->size;
        }
}

void ring_clear(ringp r)
{
        memset(r->head, 0, r->size);
        r->curr = r->head;
}

int main(int argc, char **argv)
{
        ringp r = calloc(sizeof(Ring), 1);
        ring_init(r, 10);
        printf("ring: %p, size: %d, fisrt: %p\n",
                        r, r->size, r->head);
        const char *str = "12345678901234";
        int i;
        for (i = 0; i < 10; i++) {
                ring_put(r, str, strlen(str) + 1);
                printf("buffer: %s\\0, curr: %p\n", (char *)r->head, r->curr);
        }
        ring_clear(r);
        printf("buffer: %s, curr: %p\n", (char *)r->head, r->curr);
        ring_destroy(r);
        return 0;
}
