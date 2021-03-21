#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/profitable-schemes/
# Author: Miao Zhang
# Date:   2021-03-21

#################################################################################
# dp[j][k]: the ith crime, make k profit with j people
#################################################################################
class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        kMod = 10 ** 9 + 7
        dp = [[0 for _ in range(minProfit + 1)] for _ in range(n + 1)]
        for j in range(n + 1):
            dp[j][0] = 1
        for i in range(len(group)):
            g = group[i]
            p = profit[i]
            for j in range(n, g - 1, -1):
                for k in range(minProfit, -1, -1):
                    dp[j][k] += dp[j - g][max(k - p, 0)]
                    dp[j][k] %= kMod
        return dp[n][minProfit]
