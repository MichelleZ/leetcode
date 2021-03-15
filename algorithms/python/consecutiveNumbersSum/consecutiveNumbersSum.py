#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/consecutive-numbers-sum/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        res = 1
        for i in range(2, int(sqrt(2 * N)) + 1):
            if (N - i * (i - 1) // 2) % i == 0:
                res += 1
        return res
