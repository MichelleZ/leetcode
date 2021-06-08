#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/second-largest-digit-in-a-string/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def secondHighest(self, s: str) -> int:
        nums = [0 for _ in range(10)]
        for c in s:
            if c.isdigit():
                nums[int(c)] = 1
        second = 0
        for i in range(9, -1, -1):
            if nums[i]:
                second += 1
                if second == 2:
                    return i
        return -1
                
