#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/finding-mk-average/
# Author: Miao Zhang
# Date:   2021-06-10

from sortedcontainers import SortedList
class MKAverage:

    def __init__(self, m: int, k: int):
        self.q = collections.deque()
        self.left = SortedList()
        self.mid = SortedList()
        self.right = SortedList()
        self.sums = 0
        self.m = m
        self.k = k
        self.n = m - 2 * k

    def addElement(self, num: int) -> None:
        if len(self.q) == self.m:
            self.remove(self.q.popleft())
        self.q.append(num)
        self.add(num)

    def calculateMKAverage(self) -> int:
        return -1 if len(self.q) < self.m else self.sums // self.n

    def add(self, num: int) -> None:
        self.left.add(num)
        if len(self.left) > self.k:
            self.sums += self.left[-1]
            self.mid.add(self.left[-1])
            self.left.pop()
        if len(self.mid) > self.n:
            self.sums -= self.mid[-1]
            self.right.add(self.mid[-1])
            self.mid.pop()

    def remove(self, num: int) -> None:
        if num <= self.left[-1]:
            self.left.remove(num)
        elif num <= self.mid[-1]:
            self.sums -= num
            self.mid.remove(num)
        else:
            self.right.remove(num)
        if len(self.left) < self.k:
            self.sums -= self.mid[0]
            self.left.add(self.mid[0])
            self.mid.pop(0)
        if len(self.mid) < self.n:
            self.sums += self.right[0]
            self.mid.add(self.right[0])
            self.right.pop(0)


# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()
