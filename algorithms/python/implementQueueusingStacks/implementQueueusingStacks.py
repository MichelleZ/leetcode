#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/implement-queue-using-stacks/
# Author: Miao Zhang
# Date:   2021-01-28

class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []
        self.tmp = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        while len(self.stack):
            self.tmp.append(self.stack.pop())
        self.tmp.append(x)
        while len(self.tmp):
            self.stack.append(self.tmp.pop())

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.stack):
            return self.stack.pop()
        else:
            return -1

    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self.stack):
            return self.stack[-1]
        else:
            return -1

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.stack) == 0
        

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
