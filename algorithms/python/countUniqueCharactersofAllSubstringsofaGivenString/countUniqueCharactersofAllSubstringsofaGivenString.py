#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def uniqueLetterString(self, s: str) -> int:
        idx = collections.defaultdict(list)
        for i, c in enumerate(s):
            idx[c].append(i)
        res = 0
        for v in idx.values():
            v = [-1] + v + [len(s)]
            for i in range(1, len(v) - 1):
                res += (v[i] - v[i - 1]) * (v[i + 1] - v[i])
        return res
