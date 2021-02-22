#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
# Author: Miao Zhang
# Date:   2021-02-22

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        res = 0
        for ch in root.children:
            res = max(res, self.maxDepth(ch))
        return 1 + res

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if not root: return 0
        if not root.children: return 1
        return max(self.maxDepth(ch) for ch in root.children) + 1
