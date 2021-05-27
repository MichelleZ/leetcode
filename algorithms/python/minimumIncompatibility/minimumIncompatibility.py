#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-incompatibility/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        n = len(nums)
        m = n // k
        dp = [[float('inf') for _ in range(n)] for _ in range(1 << n)]
        for i in range(n):
            dp[1 << i][i] = 0
        for mask in range(1 << n):
            for i in range(n):
                if mask & (1 << i) == 0: continue
                for j in range(n):
                    if mask & (1 << j): continue
                    t = mask | (1 << j)
                    if bin(mask).count('1') % m == 0:
                        dp[t][j] = min(dp[t][j], dp[mask][i])
                    elif nums[j] > nums[i]:
                        dp[t][j] = min(dp[t][j],
                                       dp[mask][i] + nums[j] - nums[i])
        res = min(dp[(1 << n) - 1])
        return -1 if res == float('inf') else res
