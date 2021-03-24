#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-only-letters/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        letters = [c for c in S if c.isalpha()]
        res = []
        for c in S:
            if c.isalpha():
                res.append(letters.pop())
            else:
                res.append(c)
        return ''.join(res)
