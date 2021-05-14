#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/can-convert-string-in-k-moves/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False
        cnt = [0] * 26
        for i in range(len(s)):
            d = (ord(t[i]) - ord(s[i]) + 26) % 26
            c = cnt[d]
            cnt[d] += 1
            if d != 0 and d + c * 26 > k:
                return False
        return True
