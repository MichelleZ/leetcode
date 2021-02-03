#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/house-robber-iii/
# Author: Miao Zhang
# Date:   2021-02-03

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:
        dic = dict()
        return self.dfs(root, dic)
    
    def dfs(self, root: TreeNode, dic: dict) -> int:
        if not root: return 0
        if root in dic: return dic[root]
        val = root.val
        ll = self.dfs(root.left.left, dic) if root.left else 0
        lr = self.dfs(root.left.right, dic) if root.left else 0
        rl = self.dfs(root.right.left, dic) if root.right else 0
        rr = self.dfs(root.right.right, dic) if root.right else 0
        dic[root] = max(val + ll + lr + rl + rr, self.dfs(root.left, dic) + self.dfs(root.right, dic))
        return dic[root]

