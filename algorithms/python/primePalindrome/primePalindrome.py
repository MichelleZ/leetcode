#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/prime-palindrome/
# Author: Miao Zhang
# Date:   2021-03-19

class Solution:
    def primePalindrome(self, N: int) -> int:
        def isPrime(n):
            return n > 1 and all(n % d for d in range(2, int(n ** 0.5) + 1))
        
        for l in range(1, 6):
            for num in range(10 ** (l - 1), 10 ** l):
                s = str(num)
                n = int(s + s[-2::-1])
                if n >= N and isPrime(n):p
                    return n
            
            for num in range(10 ** (l - 1), 10 ** l):
                s = str(num)
                n = int(s + s[-1::-1])
                if n >= N and isPrime(n):
                    return n
