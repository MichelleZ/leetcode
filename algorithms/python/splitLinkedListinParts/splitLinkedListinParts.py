#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-linked-list-in-parts/
# Author: Miao Zhang
# Date:   2021-03-04

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        cnt = 0
        head = root
        while head:
            cnt += 1
            head = head.next
        percnt = cnt // k
        remain = cnt % k
        res = [None for _ in range(k)]
        prev, head = None, root
        for i in range(k):
            res[i] = head
            for j in range(percnt + (1 if remain > 0 else 0)):
                prev = head
                head = head.next
            if prev: prev.next = None
            remain -= 1
        return res
