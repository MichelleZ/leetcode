#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
# Author: Miao Zhang
# Date:   2021-01-20

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        if len(prices) < 2: return profit
        for i in range(1, len(prices)):
            if (prices[i] > prices[i - 1]):
                profit += prices[i] - prices[i - 1]
        return profit
