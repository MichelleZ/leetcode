#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        res = 0
        for i in range(n):
            res += ((i + 1) * (n - i) + 1) // 2 * arr[i]
        return res
