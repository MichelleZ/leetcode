#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-search-tree-iterator/
# Author: Miao Zhang
# Date:   2021-01-24

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.inorder(root)
    
    def inorder(self, root: TreeNode):
        if not root:
            return
        self.inorder(root.left)
        self.stack.append(root.val)
        self.inorder(root.right)

    def next(self) -> int:
        return self.stack.pop(0)
        

    def hasNext(self) -> bool:
        return len(self.stack) != 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
