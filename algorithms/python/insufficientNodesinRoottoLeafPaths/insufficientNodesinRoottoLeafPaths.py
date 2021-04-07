#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
# Author: Miao Zhang
# Date:   2021-04-07

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        if root.left == root.right:
            return None if root.val < limit else root
        if root.left:
            root.left = self.sufficientSubset(root.left, limit - root.val)
        if root.right:
            root.right = self.sufficientSubset(root.right, limit - root.val)
        return None if root.left == root.right else root
