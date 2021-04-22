#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/deepest-leaves-sum/
# Author: Miao Zhang
# Date:   2021-04-22

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        self.res = 0
        self.maxdepth = 0
        self.dfs(root, 0)
        return self.res
    
    def dfs(self, root: TreeNode, d: int) -> None:
        if not root:
            return
        if d > self.maxdepth:
            self.maxdepth = d
            self.res = 0
        if d == self.maxdepth:
            self.res += root.val
        self.dfs(root.left, d + 1)
        self.dfs(root.right, d + 1)
        
