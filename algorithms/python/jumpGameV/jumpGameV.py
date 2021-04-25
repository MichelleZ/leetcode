#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jump-game-v/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        memo = [[] for _ in range(n)]
        for i in range(len(arr)):
            memo[i].append(arr[i])
            memo[i].append(i)
        memo.sort()
        dp = [1 for _ in range(n)]
        for v, i in memo:
            j = i + 1
            while j < min(n, i + d + 1) and arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)
                j += 1
            j = i - 1
            while j > max(-1, i - d - 1) and arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)
                j -= 1
        return max(dp)
            
