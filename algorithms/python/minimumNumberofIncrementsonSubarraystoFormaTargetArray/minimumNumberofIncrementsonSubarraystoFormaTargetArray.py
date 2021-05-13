#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        res = target[0]
        for i in range(1, len(target)):
            res += max(0, target[i] - target[i - 1])
        return res
