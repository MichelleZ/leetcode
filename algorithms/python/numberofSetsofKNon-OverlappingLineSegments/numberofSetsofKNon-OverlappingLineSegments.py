#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        return math.comb(n + k - 1, 2 * k) % (10 ** 9 + 7)
