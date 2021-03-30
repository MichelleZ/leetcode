#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/distribute-coins-in-binary-tree/
# Author: Miao Zhang
# Date:   2021-03-30

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        self.res = 0
        
        def dfs(root):
            if not root: return 0
            l = dfs(root.left)
            r = dfs(root.right)
            self.res += abs(l) + abs(r)
            return l + r + root.val - 1
        
        dfs(root)
        return self.res
