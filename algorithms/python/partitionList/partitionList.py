#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/partition-list/
# Author: Miao Zhang
# Date:   2021-01-15

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        small = ListNode(0)
        large = ListNode(0)
        ps = small
        pl = large
        while head:
            if head.val < x:
                ps.next = head
                ps = ps.next
            else:
                pl.next = head
                pl = pl.next
            tmp = head.next
            head.next = None
            head = tmp
        ps.next = large.next
        return small.next
