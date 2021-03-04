#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/self-dividing-numbers/
# Author: Miao Zhang
# Date:   2021-03-04

class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []
        for i in range(left, right + 1):
            valid = True
            for c in str(i):
                if int(c) == 0 or i % int(c) != 0:
                    valid = False
            if valid: res.append(i)
        return res
