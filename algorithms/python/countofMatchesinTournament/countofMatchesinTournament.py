#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-of-matches-in-tournament/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def numberOfMatches(self, n: int) -> int:
        res = 0
        while n > 1:
            res += n // 2 + (n & 1)
            n //= 2
        return res
