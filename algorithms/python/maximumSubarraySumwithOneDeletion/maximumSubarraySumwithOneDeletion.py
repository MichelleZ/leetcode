#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        maxval = max(arr)
        if maxval <= 0:
            return maxval
        dp0 = 0
        dp1 = 0
        res = 0
        for a in arr:
            dp1 = max(dp0, dp1 + a)
            dp0 += a
            res = max(res, dp1, dp0)
            if dp1 < 0: dp1 = 0
            if dp0 < 0: dp0 = 0
        return res
