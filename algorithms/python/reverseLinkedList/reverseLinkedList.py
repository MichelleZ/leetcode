#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-linked-list/
# Author: Miao Zhang
# Date:   2021-01-25

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head: return None
        pre = None
        cur = head
        while cur:
            nxt = cur.next;
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
