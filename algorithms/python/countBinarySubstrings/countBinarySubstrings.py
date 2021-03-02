#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-binary-substrings/
# Author: Miao Zhang
# Date:   2021-03-02

class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res = 0
        prev = 0
        cur = 1
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                res += min(prev, cur)
                prev = cur
                cur = 1
            else:
                cur += 1
        return res + min(prev, cur)
