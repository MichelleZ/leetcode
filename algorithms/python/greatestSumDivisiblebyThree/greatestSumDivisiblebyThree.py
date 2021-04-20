#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/greatest-sum-divisible-by-three/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0 for _ in range(3)]
        for num in nums:
            tmp = dp[:]
            for t in tmp:
                dp[(t + num) % 3] = max(dp[(t + num) % 3], t + num)
        return dp[0]
