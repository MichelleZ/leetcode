#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-consecutive-ones-iii/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        l = 0
        res = 0
        zeros = 0
        for r in range(len(A)):
            if A[r] == 0: zeros += 1
            while zeros > K:
                if A[l] == 0: zeros -= 1
                l += 1
            res = max(res, r - l + 1)
        return res
