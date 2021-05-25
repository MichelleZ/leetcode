#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def minDeletions(self, s: str) -> int:
        freq = collections.defaultdict(int)
        for c in s:
            freq[c] += 1
        seen = set()
        res = 0
        for k, v in freq.items():
            while v and v in seen:
                v -= 1
                res += 1
            seen.add(v)
        return res
