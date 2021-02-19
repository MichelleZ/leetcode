#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-mode-in-binary-search-tree/
# Author: Miao Zhang
# Date:   2021-02-17

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        self.res = []
        self.val = 0
        self.count = 0
        self.max_count = 0
        
        self.inorder(root)
        return self.res
    
    def inorder(self, root: TreeNode) -> None:
        if not root: return 
        self.inorder(root.left)
        self.visit(root.val)
        self.inorder(root.right)
    
    def visit(self, val: int) -> None:
        if self.count > 0 and val == self.val:
            self.count += 1
        else:
            self.val = val
            self.count = 1
        if self.count > self.max_count:
            self.max_count = self.count
            self.res.clear()
        if self.count == self.max_count:
            self.res.append(val)
