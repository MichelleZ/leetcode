#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/broken-calculator/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        if X >= Y:
            return X - Y
        if Y % 2 == 0:
            return 1 + self.brokenCalc(X, Y // 2)
        else:
            return 1 + self.brokenCalc(X, Y + 1)

