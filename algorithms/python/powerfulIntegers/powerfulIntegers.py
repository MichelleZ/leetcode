#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/powerful-integers/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        a = bound if x == 1 else (int(log(bound, x)))
        b = bound if y == 1 else (int(log(bound, y)))
        res = set()
        for i in range(a + 1):
            for j in range(b + 1):
                val = x ** i + y ** j
                if val <= bound:
                    res.add(val)
                if y == 1: break
            if x == 1: break
        return list(res)
