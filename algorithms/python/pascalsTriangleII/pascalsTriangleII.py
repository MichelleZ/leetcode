#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pascals-triangle-ii/
# Author: Miao Zhang
# Date:   2021-01-19

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]
        if rowIndex == 0: return res
        for _ in range(rowIndex):
            res = [1] + [res[i]+ res[i + 1] for i in range(len(res) - 1)] + [1]
        return res
