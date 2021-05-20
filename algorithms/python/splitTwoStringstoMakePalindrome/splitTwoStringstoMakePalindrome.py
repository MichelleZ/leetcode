#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-two-strings-to-make-palindrome/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def isPalindrome(s: str, i: int, j: int) -> bool:
            while i < j and s[i] == s[j]:
                i += 1
                j -= 1
            return i >= j

        def check(a: str, b: str) -> bool:
            i = 0
            j = len(a) - 1
            while i < len(a) and j >= 0 and a[i] == b[j]:
                i += 1
                j -= 1
            return isPalindrome(a, i, j) or isPalindrome(b, i, j)

        return check(a, b) or check(b, a)
