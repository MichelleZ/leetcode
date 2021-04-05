#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/divisor-game/
# Author: Miao Zhang
# Date:   2021-04-05

class Solution:
    def divisorGame(self, n: int) -> bool:
        self.cache = [-1] * (n + 1)
        return self.canWin(n)

    def canWin(self, n: int) -> bool:
        if n == 1: return False
        if self.cache[n] != -1:
            return self.cache[n]
        win = False
        for i in range(1, int(sqrt(n)) + 1):
            if n % i == 0:
                win |= not self.canWin(n - i)
        self.cache[n] = win
        return self.cache[n]
