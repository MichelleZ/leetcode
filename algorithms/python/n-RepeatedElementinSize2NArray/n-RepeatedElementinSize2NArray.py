#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        for k in range(1, 4):
            for i in range(len(A) - k):
                if A[i] == A[i + k]:
                    return A[i]
