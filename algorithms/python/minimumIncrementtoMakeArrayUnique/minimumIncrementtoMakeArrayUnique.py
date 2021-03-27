#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
# Author: Miao Zhang
# Date:   2021-03-27

class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        res = 0
        A.sort()
        for i in range(1, len(A)):
            if A[i] > A[i - 1]: continue
            res += A[i - 1] - A[i] + 1
            A[i] = A[i - 1] + 1
        return res
