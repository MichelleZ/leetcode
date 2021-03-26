#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/range-sum-of-bst/
# Author: Miao Zhang
# Date:   2021-03-27

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        if not root: return 0
        sums = 0
        if low <= root.val <= high:
            sums += root.val
        if root.val >= low:
            sums += self.rangeSumBST(root.left, low, high)
        if root.val <= high:
            sums += self.rangeSumBST(root.right, low, high)
        return sums
