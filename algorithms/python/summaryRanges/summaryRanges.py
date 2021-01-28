#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/summary-ranges/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        l = 0 # index
        res = []
        for i in range(1, len(nums) + 1):
            if i == len(nums) or nums[i] != nums[i - 1] + 1: 
                if l == i - 1:
                    res.append(str(nums[l]))
                else:
                    res.append(str(nums[l]) + '->' + str(nums[i - 1]))
                l = i
        return res
