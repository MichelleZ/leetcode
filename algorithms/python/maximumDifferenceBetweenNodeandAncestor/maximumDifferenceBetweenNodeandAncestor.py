#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
# Author: Miao Zhang
# Date:   2021-04-05

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root: return 0
        return self.maxDiff(root, root.val, root.val)
    
    def maxDiff(self, root: TreeNode, l: int, r: int) -> int:
        if not root: return 0
        cur = max(abs(root.val - l), abs(root.val - r))
        l = min(l, root.val)
        r = max(r, root.val)
        return max(cur, self.maxDiff(root.left, l, r),
                        self.maxDiff(root.right, l, r))
