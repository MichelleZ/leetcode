#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-window-substring/
# Author: Miao Zhang
# Date:   2021-01-14

# t for dicts
# traverse, if s[i] in dicts, dicts[i] -= 1, if dicts[i] >= 0: count += 1
# if count == len(t) collect minimum string
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import defaultdict
        dicts = defaultdict(int)
        for c in t:
            dicts[c] += 1
        res = ''
        l = 0
        count = 0
        minlen = len(s) + 1
        
        for i in range(len(s)):
            if s[i] in dicts:
                dicts[s[i]] -= 1
                if dicts[s[i]] >= 0:
                    count += 1
                while count == len(t):
                    if minlen > i - l + 1:
                        minlen = i - l + 1
                        res = s[l: i + 1]
                    if s[l] in dicts:
                        dicts[s[l]] += 1
                        if dicts[s[l]] > 0:
                            count -= 1
                    l += 1
        return res
