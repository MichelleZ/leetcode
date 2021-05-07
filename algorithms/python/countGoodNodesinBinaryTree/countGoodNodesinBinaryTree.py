#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
# Author: Miao Zhang
# Date:   2021-05-07

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return self.good(root, float('-inf'))
    
    def good(self, root: TreeNode, val: int) -> int:
        if not root: return 0
        return self.good(root.left, max(val, root.val)) + self.good(root.right, max(val, root.val)) + (1 if root.val >= val else 0)
