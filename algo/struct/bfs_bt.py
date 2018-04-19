class BetterObject(object):
    """
    because fuck setattr(object, name, val)
    """
    def setattr(self, attr, val):
        setattr(self, attr, val)


class Node(BetterObject):
    val = None
    left = None
    right = None

    def __init__(self, val):
        self.val = val


def build_row(data, parents, val_idx):
    print 'row parents and val_idx', parents, val_idx
    node_count = len(parents) * 2
    node_idx = 0
    parent_idx = 0
    siblings = []

    while val_idx < len(data) and node_idx < node_count:
        val = data[val_idx]
        ## if val is None, i.e. end of the branch
        if not val:
            node_idx += 1
            val_idx += 1
            continue

        node = Node(val)
        siblings.append(node)

        child = 'right' if node_idx % 2 else 'left'
        # setattr(parents[parent_idx], child, node)
        parents[parent_idx].setattr(child, node)

        ## next parent?
        if child == 'right':
            parent_idx += 1

        val_idx += 1
        node_idx += 1

    if val_idx + 1 >= len(data):
        return

    build_row(data, siblings, val_idx)

def print_node(node):
    print node.val
    if node.left:
        print_node(node.left)
    if node.right:
        print_node(node.right)


if __name__ == '__main__':
    """
                3
                /\
            5       6
            /\      /\
        1       3   -1  
        /\
    4       10
    """
    normalized = [3, 5, 6, 1, 3, -1, None, 4, 10]
    root = Node(normalized[0])
    build_row(normalized, [root], 1)
    print_node(root)

    """
            3
            /\
                6
                /\ 
                    9
    """
    normalized = [3, None, 6, None, 9]
    root = Node(normalized[0])
    build_row(normalized, [root], 1)
    print_node(root)
    
