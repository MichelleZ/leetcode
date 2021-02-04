#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/data-stream-as-disjoint-intervals/
# Author: Miao Zhang
# Date:   2021-02-04

class SummaryRanges:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.intervals = []

    def addNum(self, val: int) -> None:
        new_interval = [val, val]
        n = len(self.intervals)
        overlap = 0
        i = 0
        while i < n:
            if new_interval[1] + 1 < self.intervals[i][0]:
                break
            if new_interval[0] <= self.intervals[i][1] + 1:
                new_interval[0] = min(new_interval[0], self.intervals[i][0])
                new_interval[1] = max(new_interval[1], self.intervals[i][1])
                overlap += 1
            i += 1
        del self.intervals[i - overlap: i]
        self.intervals.insert(i - overlap, new_interval)
        
    def getIntervals(self) -> List[List[int]]:
        return self.intervals

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
