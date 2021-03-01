#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
# Author: Miao Zhang
# Date:   2021-02-28

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root: return -1
        s1 = root.val
        s2 = float('inf')
        q = collections.deque([root])
        found = False
        while q:
            node = q.popleft()
            if s1 < node.val < s2:
                s2 = node.val
                found = True
                continue
            if not node.left: continue
            q.append(node.left)
            q.append(node.right)
        return s2 if found else -1
