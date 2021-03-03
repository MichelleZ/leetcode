#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-linked-list/
# Author: Miao Zhang
# Date:   2021-03-03

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0
        self.dummy = ListNode(-1)
        self.tail = ListNode(-1)

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index < 0 or index >= self.size: return -1
        p = self.dummy
        while index + 1:
            p = p.next
            index -= 1
        return p.val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        head = self.dummy.next
        node = ListNode(val)
        node.next = head
        self.dummy.next = node
        if self.size == 0: self.tail = node
        self.size += 1
        return

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        node = ListNode(val)
        if self.size == 0:
            self.dummy.next = self.tail = node
        else:
            self.tail.next = node
            self.tail = node
        self.size += 1
        return

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index < 0 or index > self.size: return
        if index == 0: return self.addAtHead(val)
        if index == self.size: return self.addAtTail(val)
        p = self.dummy
        while index:
            p = p.next
            index -= 1
        node = ListNode(val)
        node.next = p.next
        p.next = node
        self.size += 1
        return

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0 or index >= self.size: return
        p = self.dummy
        for i in range(index):
            p = p.next
        q = p.next
        p.next = p.next.next
        if index == self.size - 1:
            self.tail = p
        self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
