#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
# Author: Miao Zhang
# Date:   2021-04-05

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        path, pos = list(), 0
        while pos < len(S):
            d = 0
            while S[pos] == '-':
                d += 1
                pos += 1
            val = 0
            while pos < len(S) and S[pos].isdigit():
                val = 10 * val + (ord(S[pos]) - ord('0'))
                pos += 1
            node = TreeNode(val)
            if d == len(path):
                if path:
                    path[-1].left = node
            else:
                path = path[:d]
                path[-1].right = node
            path.append(node)
        return path[0]
