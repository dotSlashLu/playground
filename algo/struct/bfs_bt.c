#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
        int val;
        struct Node *left;
        struct Node *right;
} Node_t;
typedef Node_t *Node_p;

int main(int argc, char **argv)
{
        malloc(sizeof(Node_t));
        printf("sizeof Node_p: %ld\n", sizeof(Node_t));
        return 0;
}
