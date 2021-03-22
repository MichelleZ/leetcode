#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/super-egg-drop/
# Author: Miao Zhang
# Date:   2021-03-22

class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        self.m = [[float('-inf') for _ in range(n + 1)] for _ in range(k + 1)]
        return self.dp(k, n)

    def dp(self, k: int, n: int) -> int:
        if k <= 0: return 0
        if k <= 1: return n
        if n <= 1: return n
        if self.m[k][n] != float('-inf'):
            return self.m[k][n]
        l = 1
        r = n + 1
        while l < r:
            m = l + (r - l) // 2
            broken = self.dp(k - 1, m - 1)
            unbroken = self.dp(k, n - m)
            if broken >= unbroken:
                r = m
            else:
                l = m + 1
        self.m[k][n] = 1 + self.dp(k - 1, l - 1)
        return self.m[k][n]
