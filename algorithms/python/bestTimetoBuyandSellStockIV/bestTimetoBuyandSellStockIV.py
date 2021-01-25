#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
# Author: Miao Zhang
# Date:   2021-01-25

# dp[i][0][1]: On the ith day, the first buy 
# dp[i][1][0]: On the ith day, the first sell
# 
# dp[i][j - 1][1]: On the ith day, the jth buy
# dp[i][j][0]: On the ith day, the jth sell
#
# dp[i][0][0] = 0
# dp[n][k][0] On the nth day, the kth sell
# 
# On the ith day, the jth buy = max((On the (i-1)th day, the jth buy), (On the (i-1)th day, the (j-1)th sell - prices[i]) 
# dp[i][j - 1][1] = max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0] - prices[i])
# On the ith day, the jth sell = max((On the (i-1)th day, the jth sell), (On the (i-1)th day, the jth buy + prices[i])
# dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i])
#
# Don't store i state
# At last
# dp[j - 1][1] = max(dp[j - 1][1], dp[j - 1][0] - prices[i])
# dp[j][0] = max(dp[j - 1][0], dp[j - 1][1] + prices[i])

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:
            return 0
        n = len(prices)
        if k > n // 2:
            res = 0
            for i in range(1, len(prices)):
                if prices[i] > prices[i - 1]:
                    res += prices[i] - prices[i - 1]
            return res
        
        dp = [[0, 0] for _ in range(k + 1)]
        for i in range(k + 1):
            dp[i][1] = -prices[0]
        for i in range(1, n):
            for j in range(1, k + 1):
                dp[j - 1][1] = max(dp[j - 1][1], dp[j - 1][0] - prices[i])
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i])
        return dp[k][0]

