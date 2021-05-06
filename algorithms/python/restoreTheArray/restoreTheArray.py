#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/restore-the-array/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        kMod = 10 ** 9 + 7
        n = len(s)
        dp = [0] * (n + 1)
        dp[-1] = 1
        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                continue
            num = 0
            for j in range(i + 1, n + 1):
                num = num * 10 + int(s[j - 1])
                if num > k: break
                dp[i] = (dp[i] + dp[j]) % kMod
        return dp[0]
