#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bulb-switcher-ii/
# Author: Miao Zhang
# Date:   2021-02-28

class Solution:
    def flipLights(self, n: int, m: int) -> int:
        n = min(n, 3)
        if m == 0: return 1
        if m == 1: return [2, 3, 4][n - 1]
        if m == 2: return [2, 4, 7][n - 1]
        return [2, 4, 8][n - 1]
