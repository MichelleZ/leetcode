#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-sightseeing-pair/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        res = 0
        maxnum = 0
        for i in range(len(values)):
            res = max(res, maxnum + values[i] - i)
            maxnum = max(maxnum, values[i] + i)
        return res
