#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
# Author: Miao Zhang
# Date:   2021-04-15

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        prefix = collections.defaultdict(ListNode)
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        s = 0
        while p:
            s += p.val
            prefix[s] = p
            p = p.next
        s = 0
        p = dummy
        while p:
            s += p.val
            p.next = prefix[s].next
            p = p.next
        return dummy.next
