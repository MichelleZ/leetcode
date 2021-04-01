#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        A.sort()
        for i in range(len(A)):
            if not K: break
            if A[i] < 0:
                A[i] = -A[i]
                K -= 1
        return sum(A) - (min(A) * 2 if K % 2 else 0)
