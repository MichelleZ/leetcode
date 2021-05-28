#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jump-game-vi/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [0] * n
        q = collections.deque()
        q.append(0)
        dp[0] = nums[0]
        for i in range(1, n):
            dp[i] = nums[i] + dp[q[0]]
            while q and dp[i] >= dp[q[-1]]:
                q.pop()
            while q and i - q[0] >= k:
                q.popleft()
            q.append(i)
        return dp[n - 1]
