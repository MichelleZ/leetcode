#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/linked-list-components/
# Author: Miao Zhang
# Date:   2021-03-14

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        res = 0
        g = set(G)
        while head:
            if head.val in g and (not head.next or head.next.val not in g):
                res += 1
            head = head.next
        return res
