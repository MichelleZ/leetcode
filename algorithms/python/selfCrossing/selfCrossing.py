#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/self-crossing/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def isSelfCrossing(self, x: List[int]) -> bool:
        n = len(x)
        if n < 4:
            return False
        for i in range(3, n):
            if x[i] >= x[i - 2] and x[i - 1] <= x[i - 3]:
                return True
            if i > 3 and x[i - 1] == x[i - 3] and x[i] + x[i - 4] == x[i - 2]:
                return True
            if i > 4 and x[i] + x[i - 4] >= x[i - 2] and x[i - 1] + x[i - 5] >= x[i - 3] and x[i - 3] >= x[i - 1] and x[i - 3] >= x[i - 5] and x[i - 2] >= x[i - 4] and x[i - 2] >= x[i]: 
                return True
        return False
