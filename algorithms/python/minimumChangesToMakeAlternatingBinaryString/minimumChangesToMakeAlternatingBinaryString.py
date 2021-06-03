#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def minOperations(self, s: str) -> int:
        c1, c2 = 0, 0
        for i, c in enumerate(s):
            c1 += (int(c) == i % 2)
            c2 += (int(c) != i % 2)
        return min(c1, c2)
