#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/super-ugly-number/
# Author: Miao Zhang
# Date:   2021-02-01

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        t = [0] * len(primes)
        res = [1]
        while len(res) < n:
            pow_num = pow(2, 32)
            for i in range(len(primes)):
                tmp = res[t[i]] * primes[i]
                if tmp < pow_num:
                    pow_num = tmp
            for i in range(len(primes)):
                if pow_num == res[t[i]] * primes[i]:
                    t[i] += 1
            res.append(pow_num)
        return res[-1]
