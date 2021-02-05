#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/super-pow/
# Author: Miao Zhang
# Date:   2021-02-04

class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        res = 1
        for n in b:
            res = self.pow(res, 10) * self.pow(a, n) % 1337
        return res
    
    def pow(self, a, b):
        if b == 0: return 1
        if b == 1: return a % 1337
        return self.pow(a % 1337, b // 2) * self.pow(a % 1337, b - b // 2) % 1337
