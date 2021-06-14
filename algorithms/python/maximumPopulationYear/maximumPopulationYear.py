#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-population-year/
# Author: Miao Zhang
# Date:   2021-06-14

class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        year = [0 for _ in range(2051)]
        for log in logs:
            for i in range(log[0], log[1]):
                year[i] += 1
        res = -1
        maxval = 0
        for i in range(1950, 2051):
            if year[i] > maxval:
                maxval = year[i]
                res = i
        return res
