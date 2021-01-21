#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/linked-list-cycle-ii/
# Author: Miao Zhang
# Date:   2021-01-21

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        '''
        non-cycle: a
        the perimeter of cycle: b
        from the start of cycle to meeting point: c
        slow: a + n * b + c
        fast: 2(a + n * b + c)
        fast - slow = n1 * b
        a + c = n2 * b
        '''
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                fast = head
                while fast != slow:
                    fast = fast.next
                    slow = slow.next 
                return slow
        return None
