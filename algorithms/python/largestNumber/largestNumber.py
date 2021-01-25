#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-number/
# Author: Miao Zhang
# Date:   2021-01-24

from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = list(map(str, nums))
        nums.sort(key = cmp_to_key(lambda a, b: 1 if a + b < b + a else -1))
        nums = ''.join(nums)
		return nums if nums[0] != '0' else '0'
