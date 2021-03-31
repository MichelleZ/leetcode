#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
# Author: Miao Zhang
# Date:   2021-03-31

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        vals = []
        
        def dfs(root, x, y):
            if not root: return
            vals.append((x, y, root.val))
            dfs(root.left, x - 1, y + 1)
            dfs(root.right, x + 1, y + 1)
        
        dfs(root, 0, 0)
        res = []
        lastx = -1000
        for x, y, val in sorted(vals):
            if x != lastx:
                res.append([])
                lastx = x
            res[-1].append(val)
        return res
        
