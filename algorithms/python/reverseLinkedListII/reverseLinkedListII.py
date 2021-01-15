#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-linked-list-ii/
# Author: Miao Zhang
# Date:   2021-01-15

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        # p: the node before m
        for i in range(m - 1):
            p = p.next
        
        pre = None
        cur = p.next # reverse start node
        # cur: from reverse start node to the node after the reverse end node
        for i in range(n - m + 1):
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        
        p.next.next = cur
        p.next = pre
        
        return dummy.next
