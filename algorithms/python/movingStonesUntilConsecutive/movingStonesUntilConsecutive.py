#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/moving-stones-until-consecutive/
# Author: Miao Zhang
# Date:   2021-04-05

class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        maxval = c - b - 1 + b - a - 1
        minval = 0
        if a + 1 == b and b + 1 == c:
            minval = 0
        elif a + 2 >= b or b + 2 >= c:
            minval = 1
        else:
            minval = 2
        return [minval, maxval]
