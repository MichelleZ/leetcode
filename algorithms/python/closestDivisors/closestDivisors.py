#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/closest-divisors/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        def divisors(n):
            for i in range(int(sqrt(n)), 1, -1):
                if n % i == 0:
                    return [i, n // i]
            return [1, n]
        res1 = divisors(num + 1)
        res2 = divisors(num + 2)
        return res1 if abs(res1[0] - res1[1]) < abs(res2[0] - res2[1]) else res2
