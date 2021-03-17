#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shifting-letters/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        n = 0
        s = list(S)
        for i in range(len(shifts) - 1, -1, -1):
            n += (shifts[i])
            s[i] = chr((ord(S[i]) - ord('a') + n) % 26 + ord('a'))
        return ''.join(s)
