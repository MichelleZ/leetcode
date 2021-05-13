#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high + 1) // 2 - low // 2
