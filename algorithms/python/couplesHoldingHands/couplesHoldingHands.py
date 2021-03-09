#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/couples-holding-hands/
# Author: Miao Zhang
# Date:   2021-03-08

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        res = 0
        for i in range(0, len(row), 2):
            if row[i + 1] == (row[i] ^ 1): continue
            res += 1
            for j in range(i + 1, len(row)):
                if row[j] == (row[i] ^ 1):
                    row[j] = row[i + 1]
                    row[i + 1] = row[i] ^ 1
                    break
        return res
