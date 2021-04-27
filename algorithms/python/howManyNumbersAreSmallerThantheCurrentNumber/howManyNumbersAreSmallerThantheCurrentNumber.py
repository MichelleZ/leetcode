#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
# Author: Miao Zhang
# Date:   2021-04-27

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        s = nums[:]
        s.sort()
        n = len(nums)
        res = [0 for _ in range(n)]
        for i in range(n):
            res[i] = bisect.bisect_left(s, nums[i])
        return res
