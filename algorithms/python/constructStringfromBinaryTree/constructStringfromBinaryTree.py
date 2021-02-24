#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-string-from-binary-tree/
# Author: Miao Zhang
# Date:   2021-02-24

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t: return ''
        res = ''
        left = self.tree2str(t.left)
        right = self.tree2str(t.right)
        if left or right:
            res += '(%s)' % left
        if right:
            res += '(%s)' % right
        return str(t.val) + res
