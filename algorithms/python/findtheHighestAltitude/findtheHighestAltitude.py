#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-highest-altitude/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        res = 0
        cur = 0
        for g in gain:
            cur += g
            res = max(res, cur)
        return res
