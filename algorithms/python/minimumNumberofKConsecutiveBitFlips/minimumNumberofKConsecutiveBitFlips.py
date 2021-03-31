#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def minKBitFlips(self, A: List[int], K: int) -> int:
        flipped = [0] * len(A)
        res = 0
        flip = 0
        for i in range(len(A)):
            if i >= K:
                flip ^= flipped[i - K]
            if A[i] ^ flip == 0:
                if i + K > len(A):
                    return -1
                res += 1
                flip ^= 1
                flipped[i] = 1
        return res

