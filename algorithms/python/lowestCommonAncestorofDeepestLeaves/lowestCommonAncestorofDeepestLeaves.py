#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
# Author: Miao Zhang
# Date:   2021-04-12

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root:
                return None, 0
            left, ld = dfs(root.left)
            right, rd = dfs(root.right)
            if ld == rd:
                return root, ld + 1
            elif ld > rd:
                return left, ld + 1
            else:
                return right, rd + 1
        res, h = dfs(root)
        return res
        
