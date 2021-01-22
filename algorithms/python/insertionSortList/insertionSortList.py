#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/insertion-sort-list/
# Author: Miao Zhang
# Date:   2021-01-22

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head: return None
        dummy = ListNode(0)
        dummy.next = head
        while head.next:
            if head.val <= head.next.val:
                head = head.next
            else:
                nxt = head.next
                head.next = nxt.next
                p = dummy
                while p.next.val <= nxt.val:
                    p = p.next
                nxt.next = p.next
                p.next = nxt 
        return dummy.next
