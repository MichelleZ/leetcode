#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-well-performing-interval/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        presum = 0
        res = 0
        seen = {}
        for i, h in enumerate(hours):
            presum += (1 if h > 8 else -1)
            if presum not in seen:
                seen[presum] = i
            if presum > 0:
                res = i + 1
            elif presum - 1 in seen:
                res = max(res, i - seen[presum - 1])
        return res
