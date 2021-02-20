#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/convert-bst-to-greater-tree/
# Author: Miao Zhang
# Date:   2021-02-20

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        self.sums = 0
        self.afterorder(root)
        return root

    def afterorder(self, root: TreeNode) -> None:
        if not root: return
        self.afterorder(root.right)
        self.sums += root.val
        root.val = self.sums
        self.afterorder(root.left)
