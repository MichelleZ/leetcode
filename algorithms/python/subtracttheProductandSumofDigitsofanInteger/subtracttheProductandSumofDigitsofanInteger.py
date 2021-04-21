#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        p = 1
        s = 0
        while n:
            tmp = n % 10
            p *= tmp
            s += tmp
            n //= 10
        return p - s
