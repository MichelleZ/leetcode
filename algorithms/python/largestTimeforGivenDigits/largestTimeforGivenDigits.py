#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-time-for-given-digits/
# Author: Miao Zhang
# Date:   2021-03-28

class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        res = -1
        for h1, h2, m1, m2 in itertools.permutations(arr):
            hours = 10 * h1 + h2
            mins = 10 * m1 + m2
            time = 60 * hours + mins
            if 0 <= hours < 24 and 0 <= mins < 60 and time > res:
                res = time
        return "{:02}:{:02}".format(*divmod(res, 60)) if res >= 0 else ""
