#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def minimumDistance(self, word: str) -> int:
        kRest = 26
        n = len(word)
        dp = [[float('inf') for _ in range(27)] for _ in range(n + 1)]
        dp[0][kRest] = 0
        
        def cost(c1, c2):
            if c1 == kRest: return 0
            return abs(c1 // 6 - c2 // 6) + abs(c1 % 6 - c2 % 6)
    
        for i in range(n):
            p = kRest if i == 0 else ord(word[i - 1]) - ord('A')
            c = ord(word[i]) - ord('A')
            for j in range(27):
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost(p, c))
                dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + cost(j, c))
        return min(dp[n])
