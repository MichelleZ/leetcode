#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        res = [0] * (n + 2)
        for num in nums:
            res[min(n, num)] += 1
        for i in range(n, -1, -1):
            res[i] += res[i + 1]
            if res[i] == i:
                return i
        return -1
