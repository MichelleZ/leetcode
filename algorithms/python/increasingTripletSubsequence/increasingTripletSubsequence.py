#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/increasing-triplet-subsequence/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first, second = float('inf'), float('inf')
        for num in nums:
            if num <= first:
                first = num
            elif num <= second:
                second = num
            else:
                return True
        return False
