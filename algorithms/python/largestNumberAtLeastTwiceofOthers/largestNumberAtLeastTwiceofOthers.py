#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-number-at-least-twice-of-others/
# Author: Miao Zhang
# Date:   2021-03-06

class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        maxnum = max(nums)
        if all(maxnum >= 2 * n for n in nums if n != maxnum):
            return nums.index(maxnum)
        return -1
