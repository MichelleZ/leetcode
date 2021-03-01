#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-univalue-path/
# Author: Miao Zhang
# Date:   2021-03-01

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        if not root: return 0
        self.res = 0

        def univaluePath(root: TreeNode) -> int:
            if not root: return 0
            l = univaluePath(root.left)
            r = univaluePath(root.right)
            pl = 0
            pr = 0
            if root.left and root.val == root.left.val:
                pl = l + 1
            if root.right and root.val == root.right.val:
                pr = r + 1
            self.res = max(self.res, pl + pr)
            return max(pl, pr)

        univaluePath(root)
        return self.res
