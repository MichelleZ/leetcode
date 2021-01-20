#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
# Author: Miao Zhang
# Date:   2021-01-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.maxsum = float('-inf')
        self.maxSum(root)
        return self.maxsum
    
    def maxSum(self, root: TreeNode) -> int:
        if not root: 
            return 0
        left = max(0, self.maxSum(root.left))
        right = max(0, self.maxSum(root.right))
        self.maxsum = max(self.maxsum, left + right + root.val)
        return root.val + max(0, max(left, right))
