#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/
# Author: Miao Zhang
# Date:   2021-04-24

class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        n = len(nums)
        sums = 0
        gain = 0
        hi = float('-inf')
        lo = float('inf')
        for i in range(n - 1):
            n1 = nums[i]
            n2 = nums[i + 1]
            sums += abs(n1 - n2)
            gain = max(gain, abs(nums[0] - n2) - abs(n1 - n2),
                       abs(nums[n - 1] - n1) - abs(n1 - n2))
            hi = max(hi, min(n1, n2))
            lo = min(lo, max(n1, n2))
        return sums + max(gain, (hi - lo) * 2)
