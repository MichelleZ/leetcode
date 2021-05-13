#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def numSplits(self, s: str) -> int:
        l = collections.defaultdict(int)
        r = collections.defaultdict(int)
        cr = 0
        for c in s:
            r[c] += 1
            if r[c] == 1:
                cr += 1
        cl = 0
        res = 0
        for c in s:
            l[c] += 1
            if l[c] == 1:
                cl += 1
            r[c] -= 1
            if r[c] == 0:
                cr -= 1
            res += cl == cr
        return res
        
