#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rotate-list/
# Author: Miao Zhang
# Date:   2021-01-13

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None: return head;
        dummy = ListNode(0)
        dummy.next = head
        count = 0
        pi = dummy
        while pi.next:
            count += 1
            pi = pi.next
        k = k % count
        # still original list
        if k == 0 or count == 1: return head
        
        pi.next = head
        pi = dummy
        for _ in range(count - k):
            pi = pi.next
        pj = pi.next
        pi.next = None
        return pj
