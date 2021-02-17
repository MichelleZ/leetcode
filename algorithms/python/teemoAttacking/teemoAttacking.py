#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/teemo-attacking/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if len(timeSeries) == 0: return 0
        res = 0
        for i in range(1, len(timeSeries)):
            res += duration if timeSeries[i] > timeSeries[i - 1] + duration else timeSeries[i] - timeSeries[i - 1]
        return res + duration
