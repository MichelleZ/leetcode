#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
# Author: Miao Zhang
# Date:   2021-01-18

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder == [] and inorder == []: return None
        val = preorder[0]
        root = TreeNode(val)
        idx = inorder.index(val)
        root.left = self.buildTree(preorder[1: 1 + idx], inorder[: idx])
        root.right = self.buildTree(preorder[1 + idx:], inorder[idx + 1:])
        return root
