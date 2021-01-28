#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/palindrome-linked-list/
# Author: Miao Zhang
# Date:   2021-01-28

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        if fast: slow = slow.next
        slow = self.reverse(slow)
        while slow:
            if slow.val != head.val: return False
            slow = slow.next
            head = head.next
        return True
    
    def reverse(self, cur: ListNode) -> ListNode:
        pre = None
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
