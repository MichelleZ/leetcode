#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-complete-tree-nodes/
# Author: Miao Zhang
# Date:   2021-01-27

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        '''
        if height(root.left) == height(root.right), 
        if not, root left is full
        get height from root.left
        '''
        if not root: return 0
        left_height = self.getHeight(root.left)
        right_height = self.getHeight(root.right)
        if left_height == right_height:
            return 2 ** left_height + self.countNodes(root.right)
        else:
            return 2 ** right_height + self.countNodes(root.left)
    
    def getHeight(self, node: TreeNode) -> int:
        if not node: return 0
        height = 0
        while node:
            height += 1
            node = node.left
        return height
