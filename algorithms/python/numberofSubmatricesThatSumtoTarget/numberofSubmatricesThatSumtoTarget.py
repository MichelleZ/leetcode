#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m = len(matrix)
        n = len(matrix[0])
        res = 0
        for i in range(m):
            for j in range(1, n):
                matrix[i][j] += matrix[i][j - 1]
        for i in range(n):
            for j in range(i, n):
                cnt = collections.defaultdict(int)
                cnt[0] = 1
                cur = 0
                for k in range(m):
                    cur += matrix[k][j] - (matrix[k][i - 1] if i > 0 else 0)
                    res += cnt[cur - target]
                    cnt[cur] += 1
        return res
