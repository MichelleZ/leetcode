#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.weight = []
        sums = 0
        for rect in rects:
            area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1)
            sums += area
            self.weight.append(sums)

    def pick(self) -> List[int]:
        idx = bisect.bisect_left(self.weight, random.randint(1, self.weight[-1]))
        rect = self.rects[idx]
        return [random.randint(rect[0], rect[2]), random.randint(rect[1], rect[3])]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
