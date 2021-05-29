#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/determine-if-string-halves-are-alike/
# Author: Miao Zhang
# Date:   2021-05-29

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        def cnt(string):
            return sum(c in 'aeiouAEIOU' for c in string)
        n = len(s)
        return cnt(s[:n // 2]) == cnt(s[n // 2:])
