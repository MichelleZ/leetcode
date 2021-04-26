#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        tmp = [-1, -1, -1]
        res = 0
        for i, c in enumerate(s):
            tmp[ord(c) - ord('a')] = i
            res += 1 + min(tmp)
        return res
