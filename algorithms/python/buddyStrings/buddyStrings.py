#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/buddy-strings/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def buddyStrings(self, a: str, b: str) -> bool:
        if len(a) != len(b): return False
        if a == b:
            seen = set()
            for c in a:
                if c in seen: return True
                seen.add(c)
            return False
        else:
            pairs = []
            for c, d in zip(list(a), list(b)):
                if c != d:
                    pairs.append((c, d))
                if len(pairs) >= 3: return False
            return len(pairs) == 2 and pairs[0] == pairs[1][::-1]
