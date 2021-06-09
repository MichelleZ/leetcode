#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-absolute-sum-difference/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        kMod = 10 ** 9 + 7
        n = len(nums1)
        res = 0
        gain = 0
        nums = sorted(list(set(nums1)))
        for i in range(n):
            diff = abs(nums1[i] - nums2[i])
            res += diff
            if diff <= gain: continue
            idx = bisect.bisect_left(nums, nums2[i])
            if idx != len(nums):
                gain = max(gain, diff - abs(nums[idx] - nums2[i]))
            if idx != 0:
                gain = max(gain, diff - abs(nums[idx - 1] - nums2[i]))
        return (res - gain) % kMod
