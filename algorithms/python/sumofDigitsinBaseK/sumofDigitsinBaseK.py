#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-digits-in-base-k/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def sumBase(self, n: int, k: int) -> int:
        res = 0
        while n:
            res += n % k
            n //= k
        return res
