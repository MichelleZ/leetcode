#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
# Author: Miao Zhang
# Date:   2021-02-20

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        self.preval = None
        self.min_diff = float('inf')
        self.inorder(root)
        return self.min_diff
   
    def inorder(self, root: TreeNode) -> None:
        if not root: return
        self.inorder(root.left)
        if self.preval is not None:
            self.min_diff = min(self.min_diff, abs(root.val - self.preval))
        self.preval = root.val
        self.inorder(root.right)
