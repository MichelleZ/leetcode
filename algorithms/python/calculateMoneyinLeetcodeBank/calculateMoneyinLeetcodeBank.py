#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def totalMoney(self, n: int) -> int:
        r = n // 7
        mod = n % 7
        return (28 * r +
               (7 * r * (r - 1) // 2) +
               (mod * (mod + 1) // 2) +
               (r * mod))
