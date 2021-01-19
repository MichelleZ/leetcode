#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pascals-triangle/
# Author: Miao Zhang
# Date:   2021-01-19

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(numRows):
            tmp = [1] * (i + 1)
            res.append(tmp)
            for j in range(1, i):
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j]
        return res
