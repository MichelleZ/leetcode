#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/range-sum-query-immutable/
# Author: Miao Zhang
# Date:   2021-02-01

class NumArray:

    def __init__(self, nums: List[int]):
        self.dp = [0] * (len(nums) + 1)
        for i in range(1, len(nums) + 1):
            self.dp[i] = self.dp[i - 1] + nums[i - 1]

    def sumRange(self, i: int, j: int) -> int:
        return self.dp[j + 1] - self.dp[i] 

