#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
# Author: Miao Zhang
# Date:   2021-04-03

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        
        def sums(root: TreeNode, c: int) -> int:
            if not root: return 0
            c = (c << 1) | root.val
            if not root.left and not root.right:
                return c
            return sums(root.left, c) + sums(root.right, c)
        
        return sums(root, 0)
