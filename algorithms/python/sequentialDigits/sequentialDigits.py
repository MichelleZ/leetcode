#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sequential-digits/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        for i in range(1, 10):
            num = i
            for j in range(i + 1, 10):
                num  = num * 10 + j
                if low <= num <= high:
                    res.append(num)
                if num >= high:
                    break
        res.sort()
        return res
