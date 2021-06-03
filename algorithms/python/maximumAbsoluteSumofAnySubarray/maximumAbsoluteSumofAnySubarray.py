#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        posSum, negSum, maxPosSum, minNegSum = 0, 0, 0, 0
        for num in nums:
            posSum += num
            maxPosSum = max(maxPosSum, posSum)
            if posSum < 0: posSum = 0
            negSum += num
            minNegSum = min(minNegSum, negSum)
            if negSum > 0: negSum = 0
        return max(maxPosSum, -minNegSum)
