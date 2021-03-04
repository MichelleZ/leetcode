#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/range-module/
# Author: Miao Zhang
# Date:   2021-03-03

class RangeModule:

    def __init__(self):
        self.ranges = []
        
    def _bounds(self, left, right):
        i, j = 0, len(self.ranges) - 1
        for d in (100, 10, 1):
            while i + d - 1 < len(self.ranges) and self.ranges[i + d - 1][1] < left:
                i += d;
            while j >= d - 1 and self.ranges[j - d + 1][0] > right:
                j -= d
        return i, j

    def addRange(self, left: int, right: int) -> None:
        i, j = self._bounds(left, right)
        if i <= j:
            left = min(left, self.ranges[i][0])
            right = max(right, self.ranges[j][1])
        self.ranges[i: j + 1] = [(left, right)]

    def queryRange(self, left: int, right: int) -> bool:
        i = bisect.bisect_left(self.ranges, (left, float('inf')))
        if i: i -= 1
        return (bool(self.ranges) and self.ranges[i][0] <= left and
                self.ranges[i][1] >= right)

    def removeRange(self, left: int, right: int) -> None:
        i, j = self._bounds(left, right)
        merge = []
        merge = []
        for k in range(i, j+1):
            if self.ranges[k][0] < left:
                merge.append((self.ranges[k][0], left))
            if right < self.ranges[k][1]:
                merge.append((right, self.ranges[k][1]))
        self.ranges[i:j+1] = merge


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
