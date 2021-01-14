#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
# Author: Miao Zhang
# Date:   2021-01-14

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        p1 = dummy
        while p1.next and p1.next.next:
            if p1.next.val == p1.next.next.val:
                p2 = p1.next.next
                while p2.next and p2.next.val == p1.next.val:
                    p2 = p2.next
                p1.next = p2.next
                if p1.next is None:
                    break
            else:
                p1 = p1.next
        return dummy.next
