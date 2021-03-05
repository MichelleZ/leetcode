#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/my-calendar-ii/
# Author: Miao Zhang
# Date:   2021-03-04

class MyCalendarTwo:

    def __init__(self):
        self.calendar = []
        self.overlap = []

    def book(self, start: int, end: int) -> bool:
        for s, e in self.overlap:
            if max(start, s) < min(end, e): return False
        for s, e in self.calendar:
            ss = max(s, start)
            ee = min(e, end)
            if ss < ee:
                self.overlap.append([ss, ee])
        self.calendar.append([start, end])
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
