#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def minOperations(self, n: int) -> int:
        res = 0
        avg = n
        for i in range(n // 2):
            num = 2 * i + 1
            if num < n:
                res += n - num
        return res
