#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
# Author: Miao Zhang
# Date:   2021-04-27

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        self.res = 0
        def dfs(root: TreeNode) -> List[int]:
            if not root:
                return [0, 0]
            ll, lr = dfs(root.left)
            rl, rr = dfs(root.right)
            l = (lr + 1) if root.left else 0
            r = (rl + 1) if root.right else 0
            self.res = max(self.res, l, r)
            return [l, r]
        dfs(root)
        return self.res
