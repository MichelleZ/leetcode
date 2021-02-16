#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/predict-the-winner/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        return True if self.getScore(nums, dp, 0, n - 1) >= 0 else False
        
    def getScore(self, nums: List[int], dp: List[List[int]], l: int, r: int) -> int:
        if l == r: return nums[l]
        if dp[l][r] > 0: return dp[l][r]
        dp[l][r] = max(nums[l] - self.getScore(nums, dp, l + 1, r), nums[r] - self.getScore(nums, dp, l, r - 1))
        return dp[l][r]
