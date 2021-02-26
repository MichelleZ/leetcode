#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/2-keys-keyboard/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def minSteps(self, n: int) -> int:
        res = 0
        i = 2
        while n > 1:
            while n % i == 0:
                res += i
                n /= i
            i += 1
        return res
