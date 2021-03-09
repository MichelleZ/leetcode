#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/swap-adjacent-in-lr-string/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        n = len(start)
        # XL -> LX L left move
        # Rx -> XR R right move
        i, j = 0, 0
        while i < n and j < n:
            while i < n and start[i] == 'X': i += 1
            while j < n and end[j] == 'X': j += 1
            if (i == n and j != n) or (i != n and j == n): return False
            if i == n and j == n: return True
            if start[i] != end[j]: return False
            if (start[i] == 'L' and i < j) or (start[i] == 'R' and i > j): return False
            i += 1
            j += 1

        while i < n:
            if start[i] != 'X': return False
            i += 1

        while j < n:
            if end[j] != 'X': return False
            j += 1

        return True
