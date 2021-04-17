#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = collections.defaultdict(int)
        res = 0
        for a in arr:
            dp[a] = dp[a - difference] + 1
            res = max(res, dp[a])
        return res
