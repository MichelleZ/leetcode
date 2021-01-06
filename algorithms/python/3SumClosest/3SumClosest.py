#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/3sum-closest/
# Author: Miao Zhang
# Date:   2021-01-05

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = sum(nums[:3])
        for i in range(len(nums)):
            l = i + 1
            r = len(nums) - 1
            while l < r:
                tmp = nums[i] + nums[l] + nums[r]
                if abs(res - target) > abs(tmp - target):
                    res = tmp
                elif target < tmp:
                    r -= 1
                else:
                    l += 1
        return res


