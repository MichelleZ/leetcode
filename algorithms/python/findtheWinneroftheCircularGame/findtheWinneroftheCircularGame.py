#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        return self.f(n, k) + 1
    
    def f(self, n: int, k: int) -> int:
        if n == 1: return 0
        return (self.f(n - 1, k) + k) % n 
