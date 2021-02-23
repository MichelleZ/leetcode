#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/permutation-in-string/
# Author: Miao Zhang
# Date:   2021-02-23

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter
        from collections import defaultdict
        n1 = len(s1)
        c1 = Counter(s1)
        c2 = Counter(s2[0:n1])
        if c1 == c2: return True
        for i in range(n1, len(s2)):
            c2[s2[i - n1]] -= 1
            if c2[s2[i - n1]] == 0: del c2[s2[i - n1]]
            c2[s2[i]] += 1
            if c1 == c2: return True
        return False
