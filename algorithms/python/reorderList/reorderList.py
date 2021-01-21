#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reorder-list/
# Author: Miao Zhang
# Date:   2021-01-21

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return
        
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        head2 = slow.next
        slow.next = None

        # reverse linked list head2     
        pre = None
        cur = head2
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt

        # merge two linked list head1 and head2
        p1 = head
        p2 = pre
        while p2:
            tmp1 = p1.next
            tmp2 = p2.next
            p1.next = p2
            p2.next = tmp1
            p1 = tmp1
            p2 = tmp2
