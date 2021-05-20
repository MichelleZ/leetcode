#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/even-odd-tree/
# Author: Miao Zhang
# Date:   2021-05-20

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        vals = {}
        def dfs(root: TreeNode, d: int) -> bool:
            if not root: return True
            if d not in vals:
                vals[d] = 0 if d % 2 == 0 else 10 ** 9
            if d % 2 == 0:
                if root.val % 2 == 0 or root.val <= vals[d]:
                    return False
            if d % 2 == 1:
                if root.val % 2 == 1 or root.val >= vals[d]:
                    return False
            vals[d] = root.val
            return dfs(root.left, d + 1) and dfs(root.right, d + 1)
        return dfs(root, 0)

