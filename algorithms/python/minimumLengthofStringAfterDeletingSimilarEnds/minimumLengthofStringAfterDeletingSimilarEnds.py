#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def minimumLength(self, s: str) -> int:
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]: break
            c = s[l]
            while l <= r and s[l] == c: l += 1
            while l <= r and s[r] == c: r -= 1
        return r - l + 1
