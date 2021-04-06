#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
# Author: Miao Zhang
# Date:   2021-04-06

from functools import lru_cache
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @lru_cache(None)
        def dp(i, j):
            return 0 if j - i <= 1 else min(dp(i, k) + dp(k, j) + values[i] * values[k] * values[j] for k in range(i + 1, j))
        return dp(0, len(values) - 1)
