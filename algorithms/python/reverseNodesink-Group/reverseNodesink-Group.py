#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-nodes-in-k-group/
# Author: Miao Zhang
# Date:   2021-01-06

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while pre:
            pre = self.reverse(pre, k)
        return dummy.next
    
    def reverse(self, pre: ListNode, k: int) -> ListNode:
        last = pre
        for i in range(k + 1):
            last = last.next
            if i != k and last is None:
                return None
        
        tail = pre.next
        cur = pre.next.next
        while cur != last:
            nxt = cur.next
            cur.next = pre.next
            pre.next = cur
            tail.next = nxt
            cur = nxt
        return tail
