#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Author: Miao Zhang
# Date:   2021-01-19

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2:
            return 0
        profit = 0
        minval = prices[0]
        for val in prices:
            minval = min(minval, val)
            profit = max(val - minval, profit)
        return profit
