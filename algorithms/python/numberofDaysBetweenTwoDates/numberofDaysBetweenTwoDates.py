#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-days-between-two-dates/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        def isLeap(year):
            return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
        
        def date2Int(year, month, day):
            for i in range(1971, year):
                day += 365 + isLeap(i)
            for i in range(1, month):
                day += months[i - 1]
            day += month > 2 and isLeap(year)
            return day
        
        y1, m1, d1 = date1.split('-')
        y2, m2, d2 = date2.split('-')
        return abs(date2Int(int(y1), int(m1), int(d1)) - date2Int(int(y2), int(m2), int(d2)))
