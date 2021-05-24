#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        kMod = 10 ** 9 + 7
        n = len(target)
        m = len(words[0])
        dp = [0] * n
        for i in range(m):
            cnt = collections.defaultdict(int)
            for word in words:
                cnt[word[i]] += 1
            for j in range(min(i, n - 1), -1, -1):
                dp[j] = (dp[j] + (dp[j - 1] if j > 0 else 1) * cnt[target[j]]) % kMod
        return dp[n - 1]
