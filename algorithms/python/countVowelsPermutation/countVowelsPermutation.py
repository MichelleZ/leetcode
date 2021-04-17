#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-vowels-permutation/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        kMod = 10 ** 9 + 7
        a, e, i, o, u = 1, 1, 1, 1, 1
        for k in range(2, n + 1):
            aa = (e + i + u) % kMod
            ee = (a + i) % kMod
            ii = (e + o) % kMod
            oo = i % kMod
            uu = (i + o) % kMod
            a = aa
            e = ee
            i = ii
            o = oo
            u = uu
        return (a + e + i + o + u) % kMod
