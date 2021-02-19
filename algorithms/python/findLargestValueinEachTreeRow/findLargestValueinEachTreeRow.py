#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
# Author: Miao Zhang
# Date:   2021-02-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        res = []
        self.inorder(root, 0, res)
        return res
    
    def inorder(self, root: TreeNode, level: int, res: List[int]) -> None:
        if not root: return
        if len(res) <= level:
            res.append(float('-inf'))
        self.inorder(root.left, level + 1, res)
        res[level] = max(res[level], root.val)
        self.inorder(root.right, level+ 1, res)
