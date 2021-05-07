#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxst = []
        minst = []
        res = 0
        l = 0
        for r in range(len(nums)):
            while minst and nums[r] < minst[-1]:
                minst.pop()
            while maxst and nums[r] > maxst[-1]:
                maxst.pop()
            minst.append(nums[r])
            maxst.append(nums[r])
            while maxst[0] - minst[0] > limit:
                if minst[0] == nums[l]: minst.pop(0)
                if maxst[0] == nums[l]: maxst.pop(0)
                l += 1
            res = max(res, r - l + 1)
        return res
