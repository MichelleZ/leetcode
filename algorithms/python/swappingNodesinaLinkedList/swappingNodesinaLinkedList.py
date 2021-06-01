#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
# Author: Miao Zhang
# Date:   2021-06-01

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        l = 0
        p = head
        while p:
            p = p.next
            l += 1
        p = head
        n1 = None
        n2 = None
        for i in range(1, l + 1):
            if i == k: n1 = p
            if i == l - k + 1: n2 = p
            p = p.next
        n1.val, n2.val = n2.val, n1.val
        return head
