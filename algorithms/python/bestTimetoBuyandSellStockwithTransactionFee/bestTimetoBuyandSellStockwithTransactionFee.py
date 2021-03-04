#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
# Author: Miao Zhang
# Date:   2021-03-03

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        sold = 0
        hold = -prices[0]
        for p in prices:
            tmp = sold
            sold = max(sold, hold + p - fee)
            hold = max(hold, tmp - p)
        return sold
