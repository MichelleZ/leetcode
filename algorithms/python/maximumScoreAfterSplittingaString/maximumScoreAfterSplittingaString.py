#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def maxScore(self, s: str) -> int:
        ones = 0
        for c in s:
            if c == '1':
                ones += 1
        zeros = 0
        res = 0
        for i in range(len(s) - 1):
            if s[i] == '0': zeros += 1
            else: ones -= 1
            res = max(res, zeros + ones)
        return res
