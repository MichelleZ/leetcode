#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/merge-in-between-linked-lists/
# Author: Miao Zhang
# Date:   2021-05-26

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy = ListNode(0, list1)
        preva = dummy
        for i in range(a):
            preva = preva.next
        nodeb = preva.next
        for i in range(a, b + 1):
            nodeb = nodeb.next
        tail2 = list2
        while tail2.next:
            tail2 = tail2.next
        preva.next = list2
        tail2.next = nodeb
        return list1
