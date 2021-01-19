#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
# Author: Miao Zhang
# Date:   2021-01-19

"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return None
        tmp = root
        q = [root]
        while q:
            n = len(q)
            for i in range(n):
                node = q.pop(0)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                if i < n - 1:
                    node.next = q[0]
        return tmp
