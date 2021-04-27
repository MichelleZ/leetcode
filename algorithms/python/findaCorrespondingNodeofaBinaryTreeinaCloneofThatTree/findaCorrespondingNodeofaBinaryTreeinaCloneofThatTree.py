#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
# Author: Miao Zhang
# Date:   2021-04-28

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if not original: return None
        if original == target: return cloned
        l = self.getTargetCopy(original.left, cloned.left, target)
        r = self.getTargetCopy(original.right, cloned.right, target)
        return l if l else r
