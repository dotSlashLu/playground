typedef struct {
        int size;
        void *head;
        void *tail;
        /* current UNUSED position */
        void *curr;
} Ring;
typedef Ring *ringp;

ringp ring_init(ringp r, int size);
short ring_destroy(ringp r);
void *ring_put(ringp r, const void *, int);
void ring_clear(ringp r);
