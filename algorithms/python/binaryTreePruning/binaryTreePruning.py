#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-pruning/
# Author: Miao Zhang
# Date:   2021-03-13

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if not root: return root
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        return root if root.val == 1 or root.left or root.right else None
