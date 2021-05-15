#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def minDays(self, n: int) -> int:
        @lru_cache(None)
        def dp(n):
            if n <= 1: return n
            return 1 + min(n % 2 + dp(n // 2), n % 3 + dp(n // 3))
        return dp(n)
