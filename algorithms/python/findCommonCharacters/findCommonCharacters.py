#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-common-characters/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        mincnt = [float('inf')] * 26
        for a in A:
            cnt = [0] * 26
            for c in a:
                cnt[ord(c) - ord('a')] += 1
            for i in range(26):
                mincnt[i] = min(mincnt[i], cnt[i])
        res = []
        for i in range(26):
            if mincnt[i] == float('inf'): continue
            for j in range(mincnt[i]):
                res.append(chr(ord('a') + i))
        return res
