#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/print-binary-tree/
# Author: Miao Zhang
# Date:   2021-02-26

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        h = self.getHeight(root)
        w = 2 ** h - 1
        res = [['' for _ in range(w)] for _ in range(h)]
        self.fill(root, res, 0, 0, w - 1)
        return res
    
    def getHeight(self, root: TreeNode) -> int:
        if not root: return 0
        return 1 + max(self.getHeight(root.left), self.getHeight(root.right))
    
    def fill(self, root: TreeNode, res: List[List[str]], h: int, l: int, r: int) -> None:
        if not root: return
        mid = (l + r) // 2;
        res[h][mid] = str(root.val)
        self.fill(root.left, res, h + 1, l, mid - 1)
        self.fill(root.right, res, h + 1, mid + 1, r)
