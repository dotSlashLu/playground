#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
        int val;
        struct TreeNode *l;
        struct TreeNode *r;
};

typedef struct TreeNode Node_t;

// Node_t *merge(Node_t *a, Node_t *b)
// {
//         Node_t *dst = malloc(sizeof(Node_t));
//         if (!a && !b)
//                 return dst;
//         dst->val = a ? a->val : 0;
//         dst->val += b ? b->val : 0;
//         merge(dst->left, merge(a->left, b->left));
//         merge(dst->right, merge(a->right, b->right));
//         return dst;
// }
//
// struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
//         struct TreeNode *dst = malloc(sizeof(struct TreeNode));
//         if (!t1 && !t2)
//                 return dst;
//         dst->val = t1 ? t1->val : 0;
//         dst->val += t2 ? t2->val : 0;
//
//         mergeTrees(dst->left, mergeTrees(t1 ? t1->left : 0, t2 ? t2->left : 0));
//         mergeTrees(dst->right, mergeTrees(t1 ? t1->right : 0, t2 ? t2->right : 0));
//         return dst;
// }

static int count = 0;
Node_t *tdata(int *vals, int s, int *c)
{
        Node_t *root;
        if (*c <= s) {
                root = calloc(sizeof(Node_t), 1);
                root->val = *(vals + *c);
                printf("val %d\n", *(vals + *c));
                *c = *c + 1;
        }
        else
                return NULL;

        if (count++ % 2)
                goto RIGHT;
LEFT:
        if (s > 1) {
                s--;
                printf("c: %d left %d\n", *c);
                root->l = tdata(vals, s, c);
                // goto RIGHT;
        }
RIGHT:
        if (s > 2) {
                s--;
                printf("c: %d right %d\n", *c, *(vals + *c));
                root->r = tdata(vals, s, c);
        }
        return root;
}


int main(int argc, char **argv)
{
        int tvals_a[8] = {1, 3, 2, 5, 3, 6, 2, 6};
        int s = 8;
        int *c = malloc(sizeof(int));
        *c = 0;
        Node_t *ta = tdata(tvals_a, s, c);
        return 0;
}
