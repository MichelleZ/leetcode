#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/odd-even-linked-list/
# Author: Miao Zhang
# Date:   2021-02-02

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head: return head
        p1 = head
        p2 = second = head.next
        while p2 and p2.next:
            p1.next = p2.next;
            p1 = p1.next
            p2.next = p1.next
            p2 = p2.next
        p1.next = second
        return head
