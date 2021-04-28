#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pizza-with-3n-slices/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        def cal(s):
            n = len(s)
            choose = (n + 1) // 3
            dp = [[0 for _ in range(choose + 1)] for _ in range(n + 1)]
            for i in range(1, n + 1):
                for j in range(1, choose + 1):
                    dp[i][j] = max(dp[i - 1][j], (dp[i - 2][j - 1] if i - 2 >= 0 else 0) + s[i - 1])
            return dp[n][choose]
        res1 = cal(slices[1:])
        res2 = cal(slices[:-1])
        return max(res1, res2)
