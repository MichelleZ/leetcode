#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
# Author: Miao Zhang
# Date:   2021-04-21

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        res = 0
        while head:
            res = res * 2 + head.val
            head = head.next
        return res
