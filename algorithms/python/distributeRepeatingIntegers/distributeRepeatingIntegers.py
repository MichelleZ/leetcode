#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/distribute-repeating-integers/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        freq = collections.defaultdict(int)
        for num in nums:
            freq[num] += 1
        cnt = []
        for k, v in freq.items():
            cnt.append(v)
        n = len(cnt)
        m = len(quantity)
        sums = [0] * (1 << m)
        for mask in range(1 << m):
            for j in range(m):
                if mask & (1 << j):
                    sums[mask] += quantity[j]
        dp = [[0 for _ in range(n + 1)] for _ in range(1 << m)]
        dp[0][0] = 1
        for mask in range(1 << m):
            for j in range(n):
                dp[mask][j + 1] |= dp[mask][j]
                cur = mask
                while cur:
                    if sums[cur] <= cnt[j] and dp[mask ^ cur][j]:
                        dp[mask][j + 1] = True
                    cur = (cur - 1) & mask
        return dp[(1 << m) - 1][n]
