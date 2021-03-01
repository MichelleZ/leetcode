#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-palindrome-ii/
# Author: Miao Zhang
# Date:   2021-03-01

class Solution:
    def validPalindrome(self, s: str) -> bool:
        isPalindrome = lambda x: x == x[::-1]
        l = 0
        r = len(s) - 1
        while l <= r:
            if s[l] != s[r]:
                return isPalindrome(s[l + 1: r + 1]) or isPalindrome(s[l: r])
            l += 1
            r -= 1
        return True
