#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
# Author: Miao Zhang
# Date:   2021-03-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        if not root: return True
        q = collections.deque([root])
        missing = False
        while q:
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                if node:
                    if missing: return False
                    q.append(node.left)
                    q.append(node.right)
                else:
                    missing = True
        return True
