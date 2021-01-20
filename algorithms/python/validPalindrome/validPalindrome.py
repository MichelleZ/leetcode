#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-palindrome/
# Author: Miao Zhang
# Date:   2021-01-19

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(filter(str.isalnum, str(s.lower())))
        return s == s[::-1]
