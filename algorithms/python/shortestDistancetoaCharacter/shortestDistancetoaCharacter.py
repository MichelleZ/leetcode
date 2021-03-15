#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-distance-to-a-character/
# Author: Miao Zhang
# Date:   2021-03-14

class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        res = [float('inf') for _ in range(n)]
        idx = -1
        for i in range(n):
            if s[i] == c: idx = i
            if idx < 0: continue
            res[i] = abs(i - idx)
        idx = -1
        for i in range(n - 1, -1, -1):
            if s[i] == c: idx = i
            if idx < 0: continue
            res[i] = min(res[i], abs(i - idx))
        return res
