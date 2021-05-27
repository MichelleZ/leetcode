#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        sums = 0
        for i in range(1, n):
            sums += (nums[i] - nums[i - 1]) * i
            res[i] += sums
        sums = 0
        for i in range(n - 2, -1, -1):
            sums += (nums[i + 1] - nums[i]) * (n - 1 - i)
            res[i] += sums
        return res
