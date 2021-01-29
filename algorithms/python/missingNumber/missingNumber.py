#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/missing-number/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        shouldsum = (n + 1) * n // 2
        total = sum(nums)
        return shouldsum - total
