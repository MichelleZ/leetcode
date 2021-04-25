#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
# Author: Miao Zhang
# Date:   2021-04-25

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        kMod = 10 ** 9 + 7
        self.res = 0
        self.sums = 0
        def dfs(root):
            if not root: return 0
            l = dfs(root.left)
            r = dfs(root.right)
            self.res = max(self.res, (self.sums - l) * l, (self.sums - r) * r)
            return l + r + root.val
        self.sums = dfs(root)
        dfs(root)
        return self.res % kMod
