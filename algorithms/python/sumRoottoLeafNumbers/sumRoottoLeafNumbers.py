#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/
# Author: Miao Zhang
# Date:   2021-01-20

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        self.res = 0
        self.dfs(root, root.val)
        return self.res
    
    def dfs(self, root, val):
        if not root.left and not root.right:
            self.res += val
        if root.left:
            self.dfs(root.left, val * 10 + root.left.val)
        if root.right:
            self.dfs(root.right, val * 10 + root.right.val)
