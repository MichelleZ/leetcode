#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        n = len(nums)
        s = 0
        for g in groups:
            found = False
            for i in range(s, n - len(g) + 1):
                if g == nums[i: i + len(g)]:
                    s = i + len(g)
                    found = True
                    break
            if not found: return False
        return True
