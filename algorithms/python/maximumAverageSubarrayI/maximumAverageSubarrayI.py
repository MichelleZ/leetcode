#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-average-subarray-i/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        res = float('-inf')
        sums = 0
        for i in range(len(nums)):
            if i >= k: sums -= nums[i - k]
            sums += nums[i]
            if i + 1 >= k: res = max(res, sums)
        return res / k
