#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        n = len(piles)
        rounds = n // 3
        res = 0
        idx = n - 2
        for i in range(rounds):
            res += piles[idx]
            idx -= 2
        return res
