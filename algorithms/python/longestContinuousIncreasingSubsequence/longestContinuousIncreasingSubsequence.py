#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
# Author: Miao Zhang
# Date:   2021-02-28

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums: return 0
        res = 1
        cur = 1
        for i in range(1, len(nums)):
            if (nums[i] > nums[i - 1]):
                cur += 1
                res = max(res, cur)
            else:
                cur = 1
        return res
