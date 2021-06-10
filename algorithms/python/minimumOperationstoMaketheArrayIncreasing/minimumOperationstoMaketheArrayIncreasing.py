#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res, last = 0, 0
        for num in nums:
            if num <= last:
                last += 1
                res += last - num
            else:
                last = num
        return res
