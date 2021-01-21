#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/word-break/
# Author: Miao Zhang
# Date:   2021-01-21

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        '''
        dp[i] = andy(dp[j] and s[j:i] in dict)
        '''
        dp = [False] * (len(s) + 1)
        dp[0] = True
        if s in wordDict:
            return True
        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp[j] and s[j: i] in wordDict:
                    dp[i] = True
                    break
        return dp[len(s)]
