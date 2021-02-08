#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-left-leaves/
# Author: Miao Zhang
# Date:   2021-02-08

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root: return 0
        val = 0
        if root.left and not root.left.left and not root.left.right:
            val += root.left.val
        return val + self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
