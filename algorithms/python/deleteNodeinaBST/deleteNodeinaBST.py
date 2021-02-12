#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/delete-node-in-a-bst/
# Author: Miao Zhang
# Date:   2021-02-12

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root: 
            return None
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        else:
            if root.left and root.right:
                min = root.right
                while min.left: min = min.left
                root.val = min.val
                root.right = self.deleteNode(root.right, min.val)
            else:
                root = root.left if root.left else root.right
        return root
