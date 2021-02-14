#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/unique-substrings-in-wraparound-string/
# Author: Miao Zhang
# Date:   2021-02-14

class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        cnt = collections.defaultdict(int)
        n = 0
        for i in range(len(p)):
            if i > 0 and (ord(p[i]) == ord(p[i - 1]) + 1 or ord(p[i - 1]) - ord(p[i]) == 25):
                n += 1
            else:
                n = 1
            cnt[p[i]] = max(cnt[p[i]], n)
        return sum(cnt.values())
