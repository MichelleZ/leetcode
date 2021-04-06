#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
# Author: Miao Zhang
# Date:   2021-04-06

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.res = 0
        
        def dfs(root):
            if not root: return
            dfs(root.right)
            self.res += root.val
            root.val = self.res
            dfs(root.left)
        
        dfs(root)
        return root
