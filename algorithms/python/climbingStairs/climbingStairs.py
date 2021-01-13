#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/climbing-stairs/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def climbStairs(self, n: int) -> int:
        res = [0 for _ in range(n + 1)]
        res[0] = 1
        res[1] = 1
        for i in range(2, n + 1):
            res[i] = res[i - 1] + res[i - 2]
        return res[n]
