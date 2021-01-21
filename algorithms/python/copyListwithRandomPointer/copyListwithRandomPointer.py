#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/copy-list-with-random-pointer/
# Author: Miao Zhang
# Date:   2021-01-21

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        nodedict = {}
        dummy = Node(0, None, None)
        newhead = dummy
        tmp = head
        while tmp:
            node = Node(tmp.val, tmp.next, None)
            nodedict[tmp] = node
            newhead.next = node
            tmp = tmp.next
            newhead = newhead.next
        tmp = head
        while tmp:
            if tmp.random:
                nodedict[tmp].random = nodedict[tmp.random]
            tmp = tmp.next
        return dummy.next
