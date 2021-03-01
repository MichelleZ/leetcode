#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/map-sum-pairs/
# Author: Miao Zhang
# Date:   2021-02-28

class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.vals = collections.defaultdict(int)
        self.sums = collections.defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        inc = val
        if key in self.vals:
            inc -= self.vals[key]
        self.vals[key] = val
        for i in range(1, len(key) + 1):
            self.sums[key[0:i]] += inc

    def sum(self, prefix: str) -> int:
        return self.sums[prefix]


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
