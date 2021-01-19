#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
        res = root
        while root:
            temp=root
            while root and root.left:
                root.left.next=root.right
                if root.next:
                    root.right.next=root.next.left
                root=root.next
            root=temp.left
        return res
