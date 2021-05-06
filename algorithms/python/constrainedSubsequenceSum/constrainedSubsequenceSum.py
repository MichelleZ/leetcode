#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/constrained-subsequence-sum/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [0] * n
        q = collections.deque()
        res = float('-inf')
        for i in range(n):
            if i > k and q[0] == i - k - 1:
                q.popleft()
            dp[i] = (0 if not q else max(dp[q[0]], 0)) + nums[i]
            while q and dp[i] >= dp[q[-1]]:
                q.pop()
            q.append(i)
            res = max(res, dp[i])
        return res
            
