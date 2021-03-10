#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
# Author: Miao Zhang
# Date:   2021-03-10

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        self.res = float('inf')
        self.prev = None
        self.inorder(root)
        return self.res
    
    def inorder(self, root: TreeNode) -> None:
        if not root: return
        self.inorder(root.left)
        if self.prev:
            self.res = min(self.res, abs(root.val - self.prev.val))
        self.prev = root
        self.inorder(root.right)
