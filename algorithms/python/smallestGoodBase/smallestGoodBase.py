#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-good-base/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def smallestGoodBase(self, n: str) -> str:
        num = int(n)
        # n = 1 + k + k^2+....k^(m - 1)
        # i:m
        for i in range(int(math.log(num + 1, 2)), 1, -1):
            # base k
            left = 2
            right = pow(num, 1 / (i - 1)) + 1
            while left < right:
                mid = int(left + (right - left) // 2)
                sums = 0
                for j in range(i):
                    sums = sums * mid + 1
                if sums == num:
                    return str(mid)
                elif sums < num:
                    left = mid + 1
                else:
                    right = mid
        return str(num - 1)

