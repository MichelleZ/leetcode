#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/swap-nodes-in-pairs/
# Author: Miao Zhang
# Date:   2021-01-06

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while head and head.next:
            cur = head
            nxt = head.next
            
            pre.next = nxt
            cur.next = nxt.next
            nxt.next = cur
            
            pre = cur
            head = cur.next
        return dummy.next
