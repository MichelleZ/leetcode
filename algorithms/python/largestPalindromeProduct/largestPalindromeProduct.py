#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-palindrome-product/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def largestPalindrome(self, n: int) -> int:
        upper = 10 ** n - 1
        lower = upper // 10
        for i in range(upper, lower, -1):
            t = str(i)
            pro = int(t + t[::-1])
            j = upper
            while j * j > pro:
                if pro % j == 0:
                    return pro % 1337
                j -= 1
        return 9
