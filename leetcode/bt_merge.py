# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        self.mergeNode(t1, t2)
        return t1

    def mergeNode(self, n1, n2):
        # 因为要merge到n1，一定要保证n1有子节点先
        if n1 and not n1.left and n2 and n2.left:
            n1.left = TreeNode(0)
        if n1 and not n1.right and n2 and n2.right:
            n1.right = TreeNode(0)

        if n1 and n2:
            n1.val += n2.val
            self.mergeNode(n1.left, n2.left)
            self.mergeNode(n1.right, n2.right)
            return

        if n1:
            self.mergeNode(n1.left, None)
            self.mergeNode(n1.right, None)
            return

        if n2:
            n1 = TreeNode(n2.val)
            n1.left = TreeNode(n2.left.val)
            n1.right = TreeNode(n2.right.val)

            self.mergeNode(n1.left, n2.left)
            self.mergeNode(n1.right, n2.right)
            return

        return

class Solution2():

    def mergeTrees(self, t1, t2):
        dst = TreeNode(0)
        return self.mergeNode(dst, t1, t2)

    def mergeNode(dst, n1, n2):
        if n1:
            dst.val += n1.val

        if n2:
            dst.val += n2.val

        if n1 and n1.left or n2 and n2.left:
            dst.left = TreeNode(0)
            l1 = None
            l2 = None
            if n1:
                l1 = n1.left
            if n2:
                l2 = n2.left
            self.mergeNode(dst.left, l1, l2)

        if n1 and n1.right or n2 and n2.right:
            dst.right = TreeNode(0)
            r1 = None
            r2 = None
            if n1:
                r1 = n1.right
            if n2:
                r2 = n2.right
            self.mergeNode(dst.right, r1, r2)
