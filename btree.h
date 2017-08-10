#if !defined(PLAY_BT_H)
#define PLAY_BT_H

#define PBT_ORDER 3
#define PBT_MAX_K (PBT_ORDER - 1) * 2
#define PBT_MIN_K PBT_ORDER - 1

struct bt_node;
struct bt_node_key;

typedef struct bt_node_key {
        int val;
        struct bt_node *prev_child;
        struct bt_node *next_child;
        /* singly linked list for the convenience of insertion */
        struct bt_node_key *next;
} bt_node_key_t;
typedef bt_node_key_t *bt_node_key_p;

typedef struct bt_node {
        int nkeys;
        /* range for quicker deciding which node to insert key */
        int min;
        int max;

        struct bt_node_key *keys;
        struct bt_node *parent;
} bt_node_t;
typedef bt_node_t *bt_node_p;

void pbt_put_key(bt_node_p root, bt_node_p prev, bt_node_p next);
void pbt_del_key(bt_node_p node, bt_node_key_p k);
void pbt_print_tree(bt_node_p root);

#endif
