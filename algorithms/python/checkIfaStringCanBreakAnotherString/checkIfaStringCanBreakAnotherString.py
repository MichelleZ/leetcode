#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-a-string-can-break-another-string/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        c1 = [0] * 26
        c2 = [0] * 26
        for i in range(len(s1)):
            c1[ord(s1[i]) - ord('a')] += 1
            c2[ord(s2[i]) - ord('a')] += 1
        t1 = 0
        t2 = 0
        res1 = 1
        res2 = 1
        for i in range(26):
            t1 += c1[i]
            t2 += c2[i]
            res1 &= (t1 <= t2)
            res2 &= (t1 >= t2)
        return res1 or res2
