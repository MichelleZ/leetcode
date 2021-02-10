#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
# Author: Miao Zhang
# Date:   2021-02-10

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        from collections import deque
        res = []
        if not root: return res
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            tmp = []
            for _ in range(n):
                node = q.popleft()
                tmp.append(node.val)
                for chd in node.children:
                    q.append(chd)
            res.append(tmp)
        return res
