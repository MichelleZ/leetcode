#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
# Author: Miao Zhang
# Date:   2021-04-23

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        res = 0

        def dfs(root, p, gp):
            nonlocal res
            if not root:
                return
            if gp % 2 == 0:
                res += root.val
            dfs(root.left, root.val, p)
            dfs(root.right, root.val, p)

        dfs(root, 1, 1)
        return res
