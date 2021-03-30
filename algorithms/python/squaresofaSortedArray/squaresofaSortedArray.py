#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/squares-of-a-sorted-array/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        i, j = 0, n - 1
        pos = n - 1
        while i <= j:
            if nums[i] * nums[i] > nums[j] * nums[j]:
                res[pos] = nums[i] * nums[i]
                i += 1
            else:
                res[pos] = nums[j] * nums[j]
                j -= 1
            pos -= 1
        return res
