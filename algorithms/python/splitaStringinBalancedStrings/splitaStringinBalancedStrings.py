#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-a-string-in-balanced-strings/
# Author: Miao Zhang
# Date:   2021-04-18

class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res = 0
        balance = 0
        for c in s:
            if c == 'L': 
                balance += 1
            else:
                balance -= 1
            if balance == 0:
                res += 1
        return res
