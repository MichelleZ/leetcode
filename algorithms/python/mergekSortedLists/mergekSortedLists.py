#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/merge-k-sorted-lists/
# Author: Miao Zhang
# Date:   2021-01-06

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy = ListNode(0)
        head = dummy
        while True:
            curHead = ListNode(float('inf'))
            curIndex = -1
            for i, Node in enumerate(lists):
                if Node and Node.val < curHead.val:
                    curHead = Node
                    curIndex = i
                if curHead.val == float('inf'):
                    break
                head.next = curHead
                head = head.next
                lists[curIndex] = curHead.next
        return dummy.next

# min heap
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy = ListNode(0)
        head = dummy
        
        heap = []
        for i, Node in enumerate(lists):
            if Node:
                heap.append((Node.val, i))
        heapq.heapify(heap)
        while heap:
            _, nodeIndex = heapq.heappop(heap)
            head.next = lists[nodeIndex]
            head = head
            if lists[nodeIndex].next:
                heapq.heappush(heap, (lists[nodeIndex].next.val,  nodeIndex))
        return dummy.next
