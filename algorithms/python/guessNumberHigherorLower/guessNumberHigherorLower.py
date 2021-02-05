#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/guess-number-higher-or-lower/
# Author: Miao Zhang
# Date:   2021-02-05

# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l = 1
        r = n
        while l <= r:
            mid = (l + r) // 2
            if not guess(mid):
                return mid
            elif guess(mid) == -1:
                r = mid - 1
            else:
                l = mid + 1
    
