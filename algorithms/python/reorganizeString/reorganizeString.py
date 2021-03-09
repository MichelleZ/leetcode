#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reorganize-string/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def reorganizeString(self, S: str) -> str:
        n = len(S)
        tmp = []
        for c, x in sorted((S.count(x), x) for x in set(S)):
            if c > (n + 1) // 2: return ""
            tmp.extend(c * x)
        res = [None] * n
        res[::2], res[1::2] = tmp[n//2:], tmp[:n//2]
        return ''.join(res)
