#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def numSteps(self, s: str) -> int:
        res = 0
        carry = 0
        for i in range(len(s) - 1, 0, -1):
            if int(s[i]) + carry == 1:
                carry = 1
                res += 2
            else:
                res += 1
        return res + carry
