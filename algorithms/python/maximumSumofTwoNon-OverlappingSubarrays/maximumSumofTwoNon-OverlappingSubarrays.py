#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
# Author: Miao Zhang
# Date:   2021-04-05

class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        n = len(A)
        sums = [0] * (n + 1)
        for i in range(n):
            sums[i + 1] = sums[i] + A[i]
        res = 0
        for i in range(n - L + 1):
            ls = sums[i + L] - sums[i]
            ms = max(self.maxSum(sums, 0, i - M, M),
                     self.maxSum(sums, i + L, n - M, M))
            res = max(res, ls + ms)
        return res

    def maxSum(self, sums: List[int], s: int, e: int, l: int) -> int:
        res = float('-inf')
        for i in range(s, e + 1):
            res = max(res, sums[i + l] - sums[i])
        return res
