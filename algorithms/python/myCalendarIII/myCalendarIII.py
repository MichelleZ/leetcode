#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/my-calendar-iii/
# Author: Miao Zhang
# Date:   2021-03-05

class Node:
    def __init__(self, l, r ,count):
        self.l = l
        self.m = -1 # split point
        self.r = r
        self.count = count
        self.left = None
        self.right = None


class MyCalendarThree:

    def __init__(self):
        self.root = Node(0, 10 ** 9, 0)
        self.max = 0

    def book(self, start: int, end: int) -> int:
        self.add(start, end, self.root)
        return self.max

    def add(self, start, end, root):
        if root.m != -1:
            if end <= root.m: self.add(start, end, root.left)
            elif start >= root.m: self.add(start, end, root.right)
            else:
                self.add(start, root.m, root.left)
                self.add(root.m, end, root.right)
            return

        if start == root.l and end == root.r:
            root.count += 1
            self.max = max(self.max, root.count)
        elif start == root.l:
            root.m = end
            root.left = Node(start, root.m, root.count + 1)
            root.right = Node(root.m, root.r, root.count)
            self.max = max(self.max, root.count + 1)
        elif end == root.r:
            root.m = start
            root.left = Node(root.l, root.m, root.count)
            root.right = Node(start, root.r, root.count + 1)
            self.max = max(self.max, root.count + 1)
        else:
            root.m = start
            root.left = Node(root.l, root.m , root.count)
            root.right = Node(root.m, root.r, root.count)
            self.add(start, end, root.right)

# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)
