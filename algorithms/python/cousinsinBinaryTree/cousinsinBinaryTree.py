#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cousins-in-binary-tree/
# Author: Miao Zhang
# Date:   2021-03-31

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        self.px = None
        self.dx = -1
        self.py = None
        self.dy = -1
        
        def preorder(root, parent, d):
            if not root: return
            if root.val == x:
                self.px, self.dx = parent, d
            if root.val == y:
                self.py, self.dy = parent, d
            preorder(root.left, root, d + 1)
            preorder(root.right, root, d + 1)
        
        preorder(root, None, 0)
        return self.dx == self.dy and self.px != self.py
