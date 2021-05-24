#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/fancy-sequence/
# Author: Miao Zhang
# Date:   2021-05-24

class Fancy:

    def __init__(self):
        self.mod = 10 ** 9 + 7
        self.vals = []
        self.a = 1
        self.b = 0
    
    def fastModularExpo(self, x: int, y: int) -> int:
        return pow(x, y, self.mod)
    
    def multiInverse(self, x: int) -> int:
        return self.fastModularExpo(x, self.mod - 2)

    def append(self, val: int) -> None:
        self.vals.append((val - self.b) * self.multiInverse(self.a) % self.mod)

    def addAll(self, inc: int) -> None:
        self.b = (self.b + inc) % self.mod

    def multAll(self, m: int) -> None:
        self.a = (self.a * m) % self.mod
        self.b = (self.b * m) % self.mod

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.vals):
            return -1
        return (self.a * self.vals[idx] + self.b) % self.mod


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
