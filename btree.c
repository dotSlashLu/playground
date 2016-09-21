#include <stdio.h>
#include "btree.h"

void pbt_put_key(bt_node_p root, int val, bt_node_p prev, bt_node_p next)
{
        // min < nkeys < max
        // simply put into the keys
        if (root->nkeys > PBT_MIN_K && root->nkeys < PBT_MAX_K) {
                while (*root->bt_node_key++ < val)
        }
}

int main(int argc, char **argv)
{
        return 0;
}
