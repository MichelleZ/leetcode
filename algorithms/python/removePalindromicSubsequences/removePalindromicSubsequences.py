#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-palindromic-subsequences/
# Author: Miao Zhang
# Date:   2021-04-24

class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if not s:
            return 0
        return 1 if s == s[::-1] else 2
