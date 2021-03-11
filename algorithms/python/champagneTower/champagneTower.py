#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/champagne-tower/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        n = 100
        dp = [0] * n
        dp[0] = poured
        for i in range(query_row):
            tmp = [0] * n
            for j in range(i + 1):
                if dp[j] > 1:
                    tmp[j] += (dp[j] - 1) / 2
                    tmp[j + 1] += (dp[j] - 1) / 2
            dp, tmp = tmp, dp
        return min(1.0, dp[query_glass])
