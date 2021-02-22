#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/student-attendance-record-ii/
# Author: Miao Zhang
# Date:   2021-02-21

class Solution:
    def checkRecord(self, n: int) -> int:
        M = 1000000007
        dp = [0] * (4 if n <= 3 else (n + 1))
        dp[0] = 1
        dp[1] = 2
        dp[2] = 4
        dp[3] = 7

        for i in range(4, n + 1):
            dp[i] = (2 * dp[i - 1]) % M + (M - dp[i - 4]) % M
        sums = dp[n]
        for i in range(1, n + 1):
            sums += (dp[i - 1] * dp[n - i]) % M
        return sums % M
