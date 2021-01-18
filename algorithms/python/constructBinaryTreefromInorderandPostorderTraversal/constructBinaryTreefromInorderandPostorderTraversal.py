#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
# Author: Miao Zhang
# Date:   2021-01-18

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if inorder == [] and postorder == []:
            return None
        val = postorder[-1]
        root = TreeNode(val)
        idx = inorder.index(val)
        root.left = self.buildTree(inorder[: idx], postorder[: idx])
        root.right = self.buildTree(inorder[idx + 1:], postorder[idx: -1])
        return root
