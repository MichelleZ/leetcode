#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-ice-cream-bars/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        res = 0
        for c in costs:
            if c > coins: break
            coins -= c
            res += 1
        return res
