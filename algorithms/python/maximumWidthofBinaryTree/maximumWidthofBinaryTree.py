#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-width-of-binary-tree/
# Author: Miao Zhang
# Date:   2021-02-26

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root: return 0
        q = collections.deque()
        # node, depth, postion
        # parent i: left 2 * i, right: 2 * i + 1
        q.append([root, 0, 0])
        cur_depth = 0
        res = 0
        left = 0
        while q:
            node, depth, pos = q.popleft()
            if node.left:
                q.append([node.left, depth + 1, pos * 2])
            if node.right:
                q.append([node.right, depth + 1, pos * 2 + 1])
            if cur_depth != depth:
                cur_depth = depth
                left = pos
            res = max(res, pos - left + 1)
        return res
