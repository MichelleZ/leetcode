#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/symmetric-tree/
# Author: Miao Zhang
# Date:   2021-01-18

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def dfs(p: TreeNode, q: TreeNode) -> bool:
            if p is None and q is None: return True
            if p is None and q: return q == None
            if p and q is None: return p == None
            if p.val != q.val: return False
            return dfs(p.left, q.right) and dfs(p.right, q.left)
        
        if root is None: return True
        return dfs(root.left, root.right)
