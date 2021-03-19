#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/score-after-flipping-matrix/
# Author: Miao Zhang
# Date:   2021-03-19

class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        m = len(A)
        n = len(A[0])
        for i in range(m):
            if A[i][0] == 0:
                for j in range(n):
                    A[i][j] ^= 1
        res = 0
        for j in range(n):
            cnt = 0
            for i in range(m):
                if A[i][j]:
                    cnt += 1
            res += (1 << n - 1 - j) * max(cnt, m - cnt)
        return res
