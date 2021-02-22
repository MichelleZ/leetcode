#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/optimal-division/
# Author: Miao Zhang
# Date:   2021-02-22

class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        nums = list(map(str, nums))
        if len(nums) <= 2:
            return '/'.join(nums)
        return '{}/({})'.format(nums[0], '/'.join(nums[1:]))
