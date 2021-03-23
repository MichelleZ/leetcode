#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/super-palindromes/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        l = int(left)
        r = int(right)
        MAGIC = 100000

        def reverse(x):
            ans = 0
            while x:
                ans = 10 * ans + x % 10
                x //= 10
            return ans

        def isPalindrome(x):
            return x == reverse(x)

        res = 0
        for i in range(MAGIC):
            s = str(i)
            t = s + s[-2::-1]
            v = int(t) ** 2
            if v > r: break
            #print(v)
            if v >= l and isPalindrome(v):
            #    print(v)
                res += 1

        for i in range(MAGIC):
            s = str(i)
            t = s + s[::-1]
            v = int(t) ** 2
            if v > r: break
            if v >= l and isPalindrome(v):
                res += 1
        return res
