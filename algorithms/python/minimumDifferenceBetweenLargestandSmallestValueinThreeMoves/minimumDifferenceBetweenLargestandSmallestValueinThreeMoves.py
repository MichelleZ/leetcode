#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 4:
            return 0
        nums.sort()
        res = float('inf')
        for i in range(4):
            res = min(res, nums[n - 4 + i] - nums[i])
        return res
