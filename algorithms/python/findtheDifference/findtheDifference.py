#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-difference/
# Author: Miao Zhang
# Date:   2021-02-06

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res = 0
        for c in s+t:
            res ^= ord(c)
        return chr(res)
