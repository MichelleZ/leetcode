#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        for i in range(1, len(nums)):
            res += nums[i] - nums[0]
        return res
