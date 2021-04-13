#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-coloring-game/
# Author: Miao Zhang
# Date:   2021-04-13

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        self.l = 0
        self.r = 0

        def nums(root: TreeNode, x: int):
            if not root: return 0
            l = nums(root.left, x)
            r = nums(root.right, x)
            if root.val == x:
                self.l = l
                self.r = r
            return 1 + l + r

        nums(root, x)
        p = n - (1 + self.l + self.r)
        return max(p, self.l, self.r) > n // 2
