#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-arithmetic-subsequence/
# Author: Miao Zhang
# Date:   2021-04-05

class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        n = len(A)
        if n == 0:
            return 0
        res = 0
        tmp = [{} for i in range(n)]
        for i in range(n):
            for j in range(0, i):
                diff = A[i] - A[j]
                if diff in tmp[j]:
                    tmp[i][diff] = tmp[j][diff] + 1
                else:
                    tmp[i][diff] = 2
                res = max(res, tmp[i][diff])
        return res
