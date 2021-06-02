#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def minCharacters(self, a: str, b: str) -> int:
        def change(a, b):
            res = float('inf')
            for c in list(string.ascii_lowercase)[:-1]:
                ops = 0
                for x in a:
                    ops += x > c
                for x in b:
                    ops += x <= c
                res = min(res, ops)
            return res
        
        res = min(change(a, b), change(b, a))
        for c in string.ascii_lowercase:
            ops = len(a) - a.count(c) + len(b) - b.count(c)
            res = min(res, ops)
        return res
