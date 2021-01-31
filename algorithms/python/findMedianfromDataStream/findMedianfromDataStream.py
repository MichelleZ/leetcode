#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-median-from-data-stream/
# Author: Miao Zhang
# Date:   2021-01-31

from heapq import *
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.max_h = list() # left side
        self.min_h = list() # right side small heap
        heapify(self.max_h)
        heapify(self.min_h)
        
    def addNum(self, num: int) -> None:
        heappush(self.min_h, num)
        heappush(self.max_h, -heappop(self.min_h))
        if len(self.max_h) > len(self.min_h):
            heappush(self.min_h, -heappop(self.max_h))
        
    def findMedian(self) -> float:
        max_len = len(self.max_h)
        min_len = len(self.min_h)
        if max_len == min_len:
            return (self.min_h[0] - self.max_h[0]) / 2.
        else:
            return self.min_h[0] / 1.
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
