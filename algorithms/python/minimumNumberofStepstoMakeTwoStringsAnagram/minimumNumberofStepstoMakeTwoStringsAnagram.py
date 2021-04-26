#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        scnt = collections.Counter(s)
        tcnt = collections.Counter(t)
        return sum((scnt-tcnt).values())
