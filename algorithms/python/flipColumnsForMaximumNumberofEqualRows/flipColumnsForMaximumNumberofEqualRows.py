#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        res = 0
        cnt = collections.defaultdict(int)
        for i in range(m):
            row = ''
            for j in range(n):
                row += str(matrix[i][0] ^ matrix[i][j])
            cnt[row] += 1
            res = max(res, cnt[row])
        return res
