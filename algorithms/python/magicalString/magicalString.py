#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/magical-string/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def magicalString(self, n: int) -> int:
        s = [1, 2, 2]
        idx = 2
        while len(s) < n:
            s += [3 - s[-1]] * s[idx]
            idx += 1
        return s[:n].count(1)
