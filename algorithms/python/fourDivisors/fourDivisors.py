#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/four-divisors/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res = 0
        for n in nums:
            r = int(sqrt(n))
            if n <= 4 or r * r == n:
                continue
            sums = 1 + n
            cnt = 2
            for d in range(2, r + 1):
                if n % d == 0:
                    sums += n // d + d
                    cnt += 2
            if cnt == 4:
                res += sums
        return res
