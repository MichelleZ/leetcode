#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/running-sum-of-1d-array/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        res = nums[:]
        for i in range(1, len(nums)):
            res[i] += res[i - 1]
        return res
