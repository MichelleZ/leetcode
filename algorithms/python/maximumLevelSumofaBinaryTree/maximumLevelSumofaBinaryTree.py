#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
# Author: Miao Zhang
# Date:   2021-04-15

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root: return 0
        q = collections.deque()
        q.append((root, 1))
        res = []
        while q:
            tmp = 0
            lenq = len(q)
            for _ in range(lenq):
                node, level = q.popleft()
                if level - 1 == len(res):
                    res.append(0)
                res[level - 1] += node.val
                if node.left:
                    q.append((node.left, level + 1))
                if node.right:
                    q.append((node.right, level + 1))
        return res.index(max(res)) + 1
