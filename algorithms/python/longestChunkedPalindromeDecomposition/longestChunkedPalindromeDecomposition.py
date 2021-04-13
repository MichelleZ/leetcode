#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
# Author: Miao Zhang
# Date:   2021-04-13

class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        if n == 0: return 0
        for l in range(1, n // 2 + 1):
            if text[0: l] == text[n - l:]:
                return 2 + self.longestDecomposition(text[l: n - l])
        return 1
