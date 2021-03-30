#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-even-numbers-after-queries/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        sums = sum(a for a in A if a % 2 == 0)
        res = []
        for val, i in queries:
            if A[i] % 2 == 0:
                sums -= A[i]
            A[i] += val
            if A[i] % 2 == 0:
                sums += A[i]
            res.append(sums)
        return res
