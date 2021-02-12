#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-all-duplicates-in-an-array/
# Author: Miao Zhang
# Date:   2021-02-11

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        if not nums: return res
        for i in range(len(nums)):
            if nums[abs(nums[i]) - 1] < 0:
                res.append(abs(nums[i]))
            else:
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]
        return res
