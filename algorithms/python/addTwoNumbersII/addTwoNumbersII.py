#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/add-two-numbers-ii/
# Author: Miao Zhang
# Date:   2021-02-12

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        s1 = 0
        while l1:
            s1 = s1 * 10 + l1.val
            l1 = l1.next
        s2 = 0
        while l2:
            s2 = s2 * 10 + l2.val
            l2 = l2.next
        s = s1 + s2
        s = str(s)
        
        dummy = ListNode(0)
        p = dummy
        for c in s:
            node = ListNode(int(c))
            p.next = node
            p = p.next
        return dummy.next
