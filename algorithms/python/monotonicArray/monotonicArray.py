#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/monotonic-array/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        inc = True
        dec = True
        for i in range(1, len(A)):
            inc &= (A[i] >= A[i - 1])
            dec &= (A[i] <= A[i - 1])
        return inc or dec
