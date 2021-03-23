#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rle-iterator/
# Author: Miao Zhang
# Date:   2021-03-23

class RLEIterator:

    def __init__(self, A: List[int]):
        self.A = A
        self.i = 0

    def next(self, n: int) -> int:
        while n != 0 and self.i < len(self.A):
            if n >= self.A[self.i]:
                n -= self.A[self.i]
                self.i += 2
                if n == 0: return self.A[self.i - 1]
            else:
                self.A[self.i] -= n
                return self.A[self.i + 1]
        return -1


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
