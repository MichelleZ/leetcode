#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-palindrome/
# Author: Miao Zhang
# Date:   2021-01-26

class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        for i in range(n, -1, -1):
            if s[:i] == s[:i][::-1]:
                return s[i:][::-1] + s
        return ""
