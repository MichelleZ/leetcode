#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-triangle-number/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        if len(nums) < 3: return 0
        nums.sort(reverse=True)
        n = len(nums)
        res = 0
        for i in range(n - 2):
            l = i + 1
            r = n - 1
            while l < r:
                if nums[l] + nums[r] > nums[i]:
                    res += (r - l)
                    l += 1
                else:
                    r -= 1
        return res
