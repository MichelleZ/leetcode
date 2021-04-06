#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-string-chain/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        n = len(words)
        dp = [1 for _ in range(n)]
        for i in range(n):
            for j in range(i):
                if self.valid(words[j], words[i]):
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)

    def valid(self, a: str, b: str) -> bool:
        if len(a) + 1 != len(b): return False
        cnt = 0
        i, j = 0, 0
        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                i += 1
                j += 1
            else:
                cnt += 1
                j += 1
        return cnt <= 1
