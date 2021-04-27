#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
# Author: Miao Zhang
# Date:   2021-04-27

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        self.res = 0
        def dfs(root):
            if not root:
                return [1e9, -1e9, 0, True]
            lmin, lmax, lsum, lvalid = dfs(root.left)
            rmin, rmax, rsum, rvalid = dfs(root.right)
            valid = lvalid and rvalid and root.val > lmax and root.val < rmin
            sums = lsum + rsum + root.val if valid else -1
            self.res = max(self.res, sums)
            return (min(lmin, root.val), max(rmax, root.val), sums, valid)
        dfs(root)
        return self.res
