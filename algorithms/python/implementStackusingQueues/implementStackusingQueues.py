#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/implement-stack-using-queues/
# Author: Miao Zhang
# Date:   2021-01-27

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []
        self.tmp = []
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.tmp.append(x)
        while len(self.queue): self.tmp.append(self.queue.pop(0))
        while len(self.tmp): self.queue.append(self.tmp.pop(0))
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.queue): 
            return self.queue.pop(0)
        

    def top(self) -> int:
        """
        Get the top element.
        """
        if len(self.queue):
            return self.queue[0]
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue) == 0
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
