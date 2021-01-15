#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/scramble-string/
# Author: Miao Zhang
# Date:   2021-01-15

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True
        if sorted(s1) != sorted(s2): return False
        
        for i in range(1, len(s1)):
            a = self.isScramble(s1[: i], s2[: i])
            b = self.isScramble(s1[i: ], s2[i: ])
            if a and b: return True
            a=self.isScramble(s1[i:],s2[:-i])
            b=self.isScramble(s1[:i],s2[-i:])
            if a and b:return True
        return False
