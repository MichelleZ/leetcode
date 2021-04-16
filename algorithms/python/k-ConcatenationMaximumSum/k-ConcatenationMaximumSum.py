#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/k-concatenation-maximum-sum/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        kMod = 10 ** 9 + 7

        def Kadane(arr):
            res = sums = 0
            for n in arr:
                sums = max(sums, 0) + n
                res = max(res, sums)
            return res

        if k > 1:
            return (Kadane(arr * 2) + (k - 2) * max(sum(arr), 0)) % kMod
        else:
            return Kadane(arr) % kMod
