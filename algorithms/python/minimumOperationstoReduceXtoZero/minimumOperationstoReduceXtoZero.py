#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
# Author: Miao Zhang
# Date:   2021-05-26

class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        res = float('inf')
        target = sum(nums) - x
        l = 0
        sums = 0
        for r in range(n):
            sums += nums[r]
            while sums > target and l <= r:
                sums -= nums[l]
                l += 1
            if sums == target:
                res = min(res, n - (r - l + 1))
        return -1 if res == float('inf') else res
