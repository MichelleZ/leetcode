#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
# Author: Miao Zhang
# Date:   2021-03-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        self.pos = 0
        self.res = []

        def solve(root):
            if not root: return
            if root.val != voyage[self.pos]:
                self.res = [-1]
                return
            if root.left and root.left.val != voyage[self.pos + 1]:
                root.left, root.right = root.right, root.left
                self.res.append(root.val)
            self.pos += 1
            solve(root.left)
            solve(root.right)

        solve(root)
        if self.res and self.res[0] == -1:
            return [-1]
        return self.res
