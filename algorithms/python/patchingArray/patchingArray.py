#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/patching-array/
# Author: Miao Zhang
# Date:   2021-02-02

class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        i = 0
        res = 0
        known_num = 1
        while known_num <= n:
            if i < len(nums) and nums[i] <= known_num:
                known_num += nums[i]
                i += 1
            else:
                res += 1
                known_num += known_num
        return res
