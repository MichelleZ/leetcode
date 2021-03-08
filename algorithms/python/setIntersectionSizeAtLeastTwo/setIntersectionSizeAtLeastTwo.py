#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/set-intersection-size-at-least-two/
# Author: Miao Zhang
# Date:   2021-03-08

class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1])) 
        print(intervals)
        todo = [2] * len(intervals)
        res = 0
        while intervals:
            (s, e), t = intervals.pop(), todo.pop()
            for p in range(s, s + t):
                for i, (s0, e0) in enumerate(intervals):
                    if todo[i] and p <= e0:
                        todo[i] -= 1
                res += 1
        return res
