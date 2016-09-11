typedef struct {
        int size;
        void *first;
        // current UNUSED position
        void *curr;
} Ring;
typedef Ring *ringp;

ringp ring_init(int size);
short ring_destroy(ringp r);
void *ring_put(ringp r, const void *, int);
void ring_clear(ringp r);
