#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-palindrome/
# Author: Miao Zhang
# Date:   2021-02-08

class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import Counter
        cnt = Counter(s)
        res = sum(i // 2 * 2 for i in cnt.values())
        return res + 1 if res < len(s) else res
