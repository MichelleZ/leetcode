#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/day-of-the-week/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        
        def leapYear(y):
            return (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0)
        
        names = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
        days = [31, 28 + leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        sums = 0
        for i in range(1970, year):
            sums += 365 + leapYear(i)
        for i in range(1, month):
            sums += days[i - 1]
        sums += day
        return names[(sums + 3) % 7]
        
