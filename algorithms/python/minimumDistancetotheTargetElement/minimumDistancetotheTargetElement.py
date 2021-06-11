#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-distance-to-the-target-element/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        res = float('inf')
        for i in range(len(nums)):
            if nums[i] == target:
                res = min(res, abs(i - start))
        return res
