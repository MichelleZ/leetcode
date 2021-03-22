#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/all-possible-full-binary-trees/
# Author: Miao Zhang
# Date:   2021-03-22

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        self.memo = {0: [], 1: [TreeNode(0)]}
        if n not in self.memo:
            res = []
            for i in range(1, n, 2):
                for left in self.allPossibleFBT(i):
                    for right in self.allPossibleFBT(n - i - 1):
                        root = TreeNode(0)
                        root.left = left
                        root.right = right
                        res.append(root)
            self.memo[n] = res
        
        return self.memo[n]
