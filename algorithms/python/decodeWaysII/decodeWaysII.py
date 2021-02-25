#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decode-ways-ii/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def numDecodings(self, s: str) -> int:
        def one(s: str) -> int:
            if s == '0': return 0
            if s == '*': return 9
            return 1
        
        def two(s: str) -> int:
            if s == '**':
                # 11-19, 21-26
                return 15
            if s[0] == '*':
                return 2 if 0 <= int(s[1]) <= 6 else 1
            if s[1] == '*':
                if s[0] == '1': return 9
                elif s[0] == '2': return 6
                return 0
            num = int(s[0]) * 10 + int(s[1])
            return num >= 10 and num <= 26
        
        if not s: return 0
        mod = 10 ** 9 + 7
        dp = [1, one(s[0])]
        for i in range(1, len(s)):
            dp_i = one(s[i]) * dp[1] + two(s[i - 1: i + 1]) * dp[0]
            dp_i %= mod
            dp[0] = dp[1]
            dp[1] = dp_i
        return dp[1]
