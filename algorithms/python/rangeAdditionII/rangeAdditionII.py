#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/range-addition-ii/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        for p in ops:
            m = min(m, p[0])
            n = min(n, p[1])
        return m * n
