#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/word-pattern/
# Author: Miao Zhang
# Date:   2021-01-30

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        ss = s.split(' ')
        if len(ss) != len(pattern): return False
        if len(set(ss)) != len(set(pattern)): return False
        return len(set(zip(ss, pattern))) == len(set(ss))
