#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        last = float('inf')
        while n:
            p = 0
            cur = 1
            while cur * 3 <= n:
                cur *= 3
                p += 1
            if p == last: return False
            last = p
            n -= cur
        return True
