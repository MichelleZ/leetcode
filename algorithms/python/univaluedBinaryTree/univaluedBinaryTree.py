#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/univalued-binary-tree/
# Author: Miao Zhang
# Date:   2021-03-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root: return True
        if root.left and root.val != root.left.val: return False
        if root.right and root.val != root.right.val: return False
        return self.isUnivalTree(root.left) and self.isUnivalTree(root.right)
