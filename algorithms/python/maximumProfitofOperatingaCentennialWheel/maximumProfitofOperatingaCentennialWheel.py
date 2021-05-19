#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        n = len(customers)
        maxc = 4
        if runningCost > maxc * boardingCost:
            return -1
        c = 0
        res = -1
        profit = 0
        maxprofit = 0
        i = 0
        while i < n or c > 0:
            c += customers[i] if i < n else 0
            profit += min(c, maxc) * boardingCost - runningCost
            c -= min(c, maxc)
            if profit > maxprofit:
                maxprofit = profit
                res = i + 1
            i += 1
        return res
