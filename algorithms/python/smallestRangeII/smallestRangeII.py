#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-range-ii/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        res = A[-1] - A[0]
        for i in range(len(A) - 1):
            a, b = A[i], A[i + 1]
            res = min(res, max(A[-1] - K, a + K) - min(A[0] + K, b - K))
        return res
