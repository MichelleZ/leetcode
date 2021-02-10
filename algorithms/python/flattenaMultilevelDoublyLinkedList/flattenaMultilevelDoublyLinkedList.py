#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
# Author: Miao Zhang
# Date:   2021-02-10

"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head: return head
        stack = []
        p = head
        while p:
            if p.child:
                if p.next:
                    stack.append(p.next)
                p.child.prev = p
                p.next = p.child
                p.child = None
            if not p.next and stack:
                last_next = stack.pop()
                p.next = last_next
                last_next.prev = p
            p = p.next
        return head
