#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        dp = ['0' for _ in range(target + 1)]
        dp[0] = ''
        for t in range(1, target + 1):
            for d in range(1, 10):
                s = t - cost[d - 1]
                if s < 0 or dp[s] == '0' or len(dp[s]) + 1 < len(dp[t]):
                    continue 
                dp[t] = str(d) + dp[s]
        return dp[target]
