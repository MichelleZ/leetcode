#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
# Author: Miao Zhang
# Date:   2021-05-08

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) < (1 << k) + k - 1:
            return False
        sub = set(s[i: i + k] for i in range(len(s) - k + 1))
        return len(sub) == (1 << k)
