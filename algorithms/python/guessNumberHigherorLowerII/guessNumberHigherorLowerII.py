#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
# Author: Miao Zhang
# Date:   2021-02-05

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        return self.solve(dp, 1, n)
    
    def solve(self, dp: List[List[int]], l: int, r: int) -> int:
        if l >= r: return 0
        if dp[l][r]: return dp[l][r]
        dp[l][r] = min(i + max(self.solve(dp, l, i - 1), self.solve(dp, i + 1, r)) for i in range(l , r+ 1))
        return dp[l][r]
