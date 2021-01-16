#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/validate-binary-search-tree/
# Author: Miao Zhang
# Date:   2021-01-16

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.isVal(root, -(2**32), 2**32)
    
    def isVal(self, node, minv, maxv):
        if not node:
            return True
        if node.left:
            if node.left.val >= node.val or node.left.val <= minv:
                return False
        if node.right:
            if node.right.val <= node.val or node.right.val >= maxv:
                return False
        return self.isVal(node.left, minv, node.val) and self.isVal(node.right, node.val, maxv)
