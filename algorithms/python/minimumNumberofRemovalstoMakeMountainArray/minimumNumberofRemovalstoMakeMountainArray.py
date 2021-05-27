#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        increase = [1] * n
        decrease = [1] * n
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    increase[i] = max(increase[i], increase[j] + 1)
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, i, -1):
                if nums[i] > nums[j]:
                    decrease[i] = max(decrease[i], decrease[j] + 1)
        res = float('inf')
        for i in range(n):
            if increase[i] < 2 or decrease[i] < 2:
                continue
            res = min(res, n - (increase[i] + decrease[i] - 1))
        return res
