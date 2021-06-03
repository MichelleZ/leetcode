#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-score-from-removing-stones/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        a, b, c = sorted([a, b, c])
        if a + b <= c:
            return a + b
        else:
            return (a + b + c) // 2
