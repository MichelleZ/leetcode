#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/repeated-substring-pattern/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        nxt = [-1 for _ in range(n + 1)]
        i, j = 0, -1
        while i < n:
            if j == -1 or s[i] == s[j]:
                i += 1
                j += 1
                nxt[i] = j
            else:
                j = nxt[j]
        return nxt[n] and n % (n - nxt[n]) == 0
