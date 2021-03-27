#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/di-string-match/
# Author: Miao Zhang
# Date:   2021-03-27

class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        res = []
        l = 0
        r = len(S)
        for c in S:
            if c == 'I':
                res.append(l)
                l += 1
            elif c == 'D':
                res.append(r)
                r -= 1
        res.append(l)
        return res
