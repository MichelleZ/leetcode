#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/coin-change-2/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for c in coins:
            for i in range(1, amount + 1):
                if c <= i:
                    dp[i] += dp[i - c]
        return dp[amount]
