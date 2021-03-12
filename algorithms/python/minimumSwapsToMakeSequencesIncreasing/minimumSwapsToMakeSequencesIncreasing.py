#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
# Author: Miao Zhang
# Date:   2021-03-12

class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        n = len(A)
        keep = [float('inf')] * n
        swap = [float('inf')] * n
        keep[0] = 0
        swap[0] = 1
        for i in range(1, n):
            if A[i] > A[i - 1] and B[i] > B[i - 1]:
                keep[i] = keep[i - 1]
                swap[i] = swap[i - 1] + 1
            if A[i] > B[i - 1] and B[i] > A[i - 1]:
                swap[i] = min(swap[i], keep[i - 1] + 1)
                keep[i] = min(keep[i], swap[i - 1])
        return min(keep[-1], swap[-1])
