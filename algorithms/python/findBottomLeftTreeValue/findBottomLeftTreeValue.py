#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-bottom-left-tree-value/
# Author: Miao Zhang
# Date:   2021-02-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        res = []
        self.dfs(root, res, 0)
        return res[-1][0]
    
    def dfs(self, root: TreeNode, res: int, level: int) -> None:
        if not root: return
        if level == len(res): res.append([])
        res[level].append(root.val)
        self.dfs(root.left, res, level + 1)
        self.dfs(root.right, res, level + 1)
