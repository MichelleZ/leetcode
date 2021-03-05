#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/monotone-increasing-digits/
# Author: Miao Zhang
# Date:   2021-03-05

class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        nlist = list(map(int, list(str(N))))
        j = len(nlist)
        for i in range(len(nlist) - 1, 0, -1):
            if nlist[i] >= nlist[i - 1]: continue
            nlist[i - 1] -= 1
            j = i
        for i in range(j, len(nlist)):
            nlist[i] = 9
        return int(''.join((map(str, nlist))))
