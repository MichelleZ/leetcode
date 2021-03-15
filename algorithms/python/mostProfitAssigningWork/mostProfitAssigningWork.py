#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/most-profit-assigning-work/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        n = 100000
        max_profit = [0] * (n + 1)
        for i in range(len(difficulty)):
            max_profit[difficulty[i]] = max(max_profit[difficulty[i]], profit[i])
        for i in range(2, n + 1):
            max_profit[i] = max(max_profit[i], max_profit[i - 1])
        res = 0
        for w in worker:
            res += max_profit[w]
        return res
