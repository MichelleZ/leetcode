#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/arithmetic-slices/
# Author: Miao Zhang
# Date:   2021-02-09

class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        dp = [0] * n
        for i in range(2, n):
            if A[i - 1] - A[i - 2] == A[i] - A[i - 1]:
                dp[i] = dp[i - 1] + 1
        return sum(dp)
