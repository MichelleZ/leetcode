#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rotate-string/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if (len(A) != len(B)): return False
        if (len(A) == 0 and len(B) == 0): return True
        for i in range(len(A)):
            if self.check(A, B, i): return True
        return False
    
    def check(self, A: str, B: str, offset: int) -> bool:
        for i in range(len(A)):
            if A[(i + offset) % len(A)] != B[i]: return False
        return True
