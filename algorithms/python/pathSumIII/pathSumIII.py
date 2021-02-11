#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/path-sum-iii/
# Author: Miao Zhang
# Date:   2021-02-11

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        res = 0
        if not root: return res
        res += self.containRootPathSum(root, sum)
        res += self.pathSum(root.left, sum)
        res += self.pathSum(root.right, sum)
        return res
    
    def containRootPathSum(self, root: TreeNode, sum: int) -> int:
        res = 0
        if not root: return 0
        if root.val == sum:
            res += 1
        res += self.containRootPathSum(root.left, sum - root.val)
        res += self.containRootPathSum(root.right, sum - root.val)
        return res
