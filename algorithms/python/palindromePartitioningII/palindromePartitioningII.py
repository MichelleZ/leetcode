#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/palindrome-partitioning-ii/
# Author: Miao Zhang
# Date:   2021-01-20

class Solution:
    def minCut(self, s: str) -> int:
        '''
        dp[i]: min cut from 0 to i(contain)
        s[j:i] is Panlindrome, dp[i] = min(dp[i], dp[j] + 1)
        '''
        dp = [i - 1 for i in range(len(s) + 1)]
        for i in range(1, len(s) + 1):
            for j in range(i):
                subs = s[j: i]
                if subs == subs[::-1]:
                    dp[i] = min(dp[i], dp[j] + 1)
        return dp[len(s)]
