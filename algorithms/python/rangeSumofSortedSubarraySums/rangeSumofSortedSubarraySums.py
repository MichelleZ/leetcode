#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        kMod = 10 ** 9 + 7
        sums = []
        for i in range(n):
            s = 0
            for j in range(i, n):
                s += nums[j]
                sums.append(s)
        sums.sort()
        return sum(sums[left - 1: right]) % kMod
