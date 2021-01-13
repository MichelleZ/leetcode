#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/permutation-sequence/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        from math import factorial
        res = ''
        nums = [i for i in range(1, n + 1)]
        n, k = len(nums), k - 1
        while n > 0:
            cur = factorial(n - 1)
            idx, k = divmod(k, cur)
            res += str(nums.pop(idx))
            n -= 1
        return res
