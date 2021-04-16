#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/dinner-plate-stacks/
# Author: Miao Zhang
# Date:   2021-04-15

from sortedcontainers import SortedSet
class DinnerPlates:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.index = SortedSet()
        self.stacks = []

    def push(self, val: int) -> None:
        idx = self.index[0] if self.index else len(self.stacks)
        if idx == len(self.stacks):
            self.stacks.append([])
        s = self.stacks[idx]
        s.append(val)
        if len(s) == self.cap:
            self.index.discard(idx)
        elif len(s) == 1 and self.cap != 1:
            self.index.add(idx)
    
    def pop(self) -> int:
        return self.popAtStack(len(self.stacks) - 1)

    def popAtStack(self, index: int) -> int:
        if index < 0 or index >= len(self.stacks) or not self.stacks[index]:
            return -1
        s = self.stacks[index]
        val = s.pop()
        if len(s) == self.cap - 1:
            self.index.add(index)
        while self.stacks and not self.stacks[-1]:
            tmp = len(self.stacks) - 1
            self.stacks.pop()
            self.index.discard(tmp)
        return val


# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
