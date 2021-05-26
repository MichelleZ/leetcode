#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-an-ordered-stream/
# Author: Miao Zhang
# Date:   2021-05-26

class OrderedStream:

    def __init__(self, n: int):
        self.data = [0] * (n + 1)
        self.ptr = 1

    def insert(self, idKey: int, value: str) -> List[str]:
        self.data[idKey] = value
        if self.ptr == idKey:
            while self.ptr < len(self.data) and self.data[self.ptr]:
                self.ptr += 1
        return self.data[idKey: self.ptr]


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
