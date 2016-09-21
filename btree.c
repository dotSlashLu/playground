#include <stdio.h>
#include "btree.h"

#define PBT_ORDER 3
#define PBT_MAX_K (PBT_ORDER - 1) * 2
#define PBT_MIN_K PBT_ORDER - 1

void pbt_put_key(bt_node_p to, bt_node_p prev, bt_node_p next)
{
        // min < nkeys < max
        // simply put into the keys
        if (to->nkeys > PBT_MIN_K && to->nkeys < PBT_MAX_K) {

        }
}
