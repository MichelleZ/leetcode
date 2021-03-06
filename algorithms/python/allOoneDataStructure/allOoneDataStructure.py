#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/all-oone-data-structure/
# Author: Miao Zhang
# Date:   2021-02-10

####################################################################
#head<====>1<===>2<===>3<===>4<===>7<===>8<===>tail
#        key11 key21 key31....
#        key12
####################################################################
class Node:
    def __init__(self, cnt):
        self.cnt = cnt
        self.keySet = set()
        self.prev = None
        self.next = None


class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = Node(float('-inf'))
        self.tail = Node(float('inf'))
        self.head.next = self.tail
        self.tail.prev = self.head
        # value 1, 2, 3, key: hello or abc
        self.cntKey = {}
        # key : hello or abc, cnt value 1, 2, 3
        self.keyCnt = {}

    def inc(self, key: str) -> None:
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        """
        if key in self.keyCnt:
            self.changeKey(key, 1)
        else:
            self.keyCnt[key] = 1
            # 说明没有计数为1的节点,在self.head后面加入
            if self.head.next.cnt != 1:
                self.addNodeAfter(Node(1), self.head)
            self.head.next.keySet.add(key)
            self.cntKey[1] = self.head.next

    def dec(self, key: str) -> None:
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        """
        if key in self.keyCnt:
            cnt = self.keyCnt[key]
            if cnt == 1:
                self.keyCnt.pop(key)
                self.removeFromNode(self.cntKey[cnt], key)
            else:
                self.changeKey(key, -1)

    def getMaxKey(self) -> str:
        """
        Returns one of the keys with maximal value.
        """
        return "" if self.tail.prev == self.head else next(iter(self.tail.prev.keySet))

    def getMinKey(self) -> str:
        """
        Returns one of the keys with Minimal value.
        """
        return "" if self.head.next == self.tail else next(iter(self.head.next.keySet))

    # key + 1 or - 1
    def changeKey(self, key, offset):
        cnt = self.keyCnt[key]
        self.keyCnt[key] = cnt + offset
        curNode = self.cntKey[cnt]
        newNode = None
        if cnt + offset in self.cntKey:
            newNode = self.cntKey[cnt + offset]
        else:
            newNode = Node(cnt + offset)
            self.cntKey[cnt + offset] = newNode
            self.addNodeAfter(newNode, curNode if offset == 1 else curNode.prev)
        newNode.keySet.add(key)
        self.removeFromNode(curNode, key)

    def addNodeAfter(self, newNode, prevNode):
        newNode.prev = prevNode
        newNode.next = prevNode.next
        prevNode.next.prev = newNode
        prevNode.next = newNode

    def removeFromNode(self, curNode, key):
        curNode.keySet.remove(key)
        if len(curNode.keySet) == 0:
            self.removeNodeFromList(curNode)
            self.cntKey.pop(curNode.cnt)

    def removeNodeFromList(self, curNode):
        curNode.prev.next = curNode.next
        curNode.next.prev = curNode.prev
        curNode.next = None
        curNode.prev = None
        

# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
