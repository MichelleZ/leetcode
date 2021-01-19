#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
# Author: Miao Zhang
# Date:   2021-01-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        step1: put the right node of root to the right side of the left node of root
        step2: put the left node of root to the right node of root
        step3: root = root.right
        """
        if not root or not root.left and not root.right:
            return root
        while root:
            if not root.left:
                root = root.right
            else:
                pre = root.left
                while pre and pre.right:
                    pre = pre.right
                pre.right = root.right
                root.right = root.left
                root.left = None
                root = root.right
