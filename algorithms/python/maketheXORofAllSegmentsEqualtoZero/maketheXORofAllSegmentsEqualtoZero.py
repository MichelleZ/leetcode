#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        n = len(nums)
        groupcnt = [0 for _ in range(k)]
        group = [collections.defaultdict(int) for _ in range(k)]
        for i in range(n):
            groupcnt[i % k] += 1
            group[i % k][nums[i]] += 1
        dp = [[0 for _ in range(1024)] for _ in range(k)]
        for j in range(1024):
            dp[0][j] = groupcnt[0] - group[0][j]
        for i in range(1, k):
            maxval = min(dp[i - 1]) + groupcnt[i]
            for j in range(1024): dp[i][j] = maxval
            for num, cnt in group[i % k]:
                for j in range(1024):
                    dp[i][j ^ num] = min(dp[i][j ^ num], dp[i - 1][j] + groupcnt[i] - cnt)
        return dp[k - 1][0]
