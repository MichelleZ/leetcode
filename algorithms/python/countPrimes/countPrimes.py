#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-primes/
# Author: Miao Zhang
# Date:   2021-01-25

class Solution:
    def countPrimes(self, n: int) -> int:
        '''
        Donot contain n,
        if contain, is_primes = [True] * (n + 1)
        '''
        if n < 2:
            return 0
        is_primes = [True] * n
        is_primes[0] = False
        is_primes[1] = False
        for i in range(2, n):
            if is_primes[i]:
                for j in range(i + i, n, i):
                    is_primes[j] = False
        return is_primes.count(True)
