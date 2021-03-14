#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/race-car/
# Author: Miao Zhang
# Date:   2021-03-14

class Solution:
    def racecar(self, target: int) -> int:
        dp = [float('inf')] * (target + 1)
        for i in range(1, target + 1):
            cnt1 = 1
            j = 1
            while j < i:
                cnt2 = 0
                k = 0
                while k < j:
                    dp[i] = min(dp[i], cnt1 + 1 + cnt2 + 1 + dp[i - (j - k)])
                    cnt2 += 1
                    k = (1 << cnt2) - 1
                cnt1 += 1
                j = (1 << cnt1) - 1
            dp[i] = min(dp[i], cnt1 + (0 if i == j else 1 + dp[j - i]))
            
        return dp[target]
