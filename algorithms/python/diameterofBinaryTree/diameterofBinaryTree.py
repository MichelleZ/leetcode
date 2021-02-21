#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/diameter-of-binary-tree/
# Author: Miao Zhang
# Date:   2021-02-21

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.diameter = 0
        self.depth(root)
        return self.diameter
    
    def depth(self, root: TreeNode) -> int:
        if not root: return 0
        left = self.depth(root.left)
        right = self.depth(root.right)
        self.diameter = max(self.diameter, left + right)
        return 1 + max(left, right)
