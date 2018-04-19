#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
        int val;
        struct stack *next;
};

// find previous node function()
struct stack* get_prevnd(
                struct stack* head,
                struct stack* a
                ){
        if(head == a){
                // node[a] is first node
                return NULL;
        }
        struct stack* temp = head; // temp is current node
        struct stack* pre_a = NULL;

        while(temp && temp!=a){ //search while not reach to end or the node
                pre_a = temp;          // find previous node
                temp = temp->next;
        }
        if(temp!=a){// node[a] not present in list
                fprintf(stderr, "\n error: node not found!\n");
                exit(EXIT_FAILURE); // bad technique to exit()
        }
        return pre_a;
}

void swap(struct stack **head,
                struct stack **a,
                struct stack **b){
        printf("a.val %d b.val %d\n", (*a)->val, (*b)->val);
        // first check if a agrgument is null
        if( (*head) == NULL ||               // Empty list
                        (*a) == NULL || (*b) == NULL){     // one node is null
                // Nothing to swap, just return
                printf("\n Nothing to swap, just return \n");
                return;
        }

        // find previos nodes
        struct stack* pre_a = get_prevnd(*head, *a);
        struct stack* pre_b = get_prevnd(*head, *b);

        //Now swap previous node's next
        if(pre_a) pre_a->next = (*b); // a's previous become b's previous, and
        if(pre_b) pre_b->next = (*a); // b's previous become a's previous

        //Now swap next fiels of candidate nodes
        struct stack* temp = NULL;
        temp = (*a)->next;
        (*a)->next = (*b)->next;
        (*b)->next = temp;

        //change head: if any node was a head
        if((*head)==(*a))
                *head = *b;
        else
                if((*head)==(*b))
                        *head = *a;
}

void pstack(struct stack *s)
{
        while(s != NULL) {
                printf("%d ", s->val);
                s = s->next;
        }
        printf("\n");
}

int main(int argc, char **argv)
{
        struct stack *n = malloc(sizeof(struct stack));
        n->val = 1;
        n->next = NULL;
        struct stack *s = malloc(sizeof(struct stack));
        s->val = 0;
        s->next = n;
        pstack(s);
        printf("s->next:%p n:%p &(s->next):%p &n:%p\n", s->next, n, &(s->next), &n);
        // swap(&s, &(s->next), &s);
        swap(&s, &n, &s);
        pstack(s);
        return 0;
}
