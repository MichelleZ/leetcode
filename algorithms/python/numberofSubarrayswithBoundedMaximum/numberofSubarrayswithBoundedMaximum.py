#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        res = 0
        left = -1
        right = -1
        for i in range(len(A)):
            if A[i] >= L: right = i
            if A[i] > R: left = i
            res += (right - left)
        return res
