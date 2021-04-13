#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/day-of-the-year/
# Author: Miao Zhang
# Date:   2021-04-13

class Solution:
    def dayOfYear(self, date: str) -> int:
        y, m, d = int(date.split('-')[0]), int(date.split('-')[1]), int(date.split('-')[2])
        leap = (y % 4 == 0 and y % 100 != 0) or y % 400 == 0
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        res = sum(days[0: m - 1]) + d
        if leap and m > 2: res += 1
        return res
