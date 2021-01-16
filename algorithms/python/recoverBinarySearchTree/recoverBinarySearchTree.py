#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/recover-binary-search-tree/
# Author: Miao Zhang
# Date:   2021-01-16

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.pre, self.first, self.second = None, None, None
        self.inorder(root)
        self.first.val, self.second.val = self.second.val, self.first.val
    
    def inorder(self, root):
        if not root: return
        self.inorder(root.left)
        if self.pre and self.pre.val > root.val:
            if not self.first:
                self.first = self.pre
            self.second = root
        self.pre = root
        self.inorder(root.right)
