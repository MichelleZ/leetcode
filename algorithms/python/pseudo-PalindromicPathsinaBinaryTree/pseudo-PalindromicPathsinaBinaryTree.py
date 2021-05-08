#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
# Author: Miao Zhang
# Date:   2021-05-08

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        return int(self.p(root, 0))
    
    def p(self, root: TreeNode, s: int) -> int:
        if not root: return 0
        s ^= (1 << root.val)
        if not root.left and not root.right:
            return bin(s).count('1') <= 1
        return self.p(root.left, s) + self.p(root.right, s)
