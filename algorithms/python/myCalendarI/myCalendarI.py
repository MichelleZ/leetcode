#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/my-calendar-i/
# Author: Miao Zhang
# Date:   2021-03-04

class MyCalendar:

    def __init__(self):
        self.calendar = []

    def book(self, start: int, end: int) -> bool:
        i = bisect.bisect_left(self.calendar, [start, end])
        if i != len(self.calendar) and self.calendar[i][0] < end:
            return False
        if i != 0 and self.calendar[i - 1][1] > start:
            return False
        self.calendar.insert(i, [start, end])
        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
