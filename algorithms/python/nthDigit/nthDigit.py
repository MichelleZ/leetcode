#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/nth-digit/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def findNthDigit(self, n: int) -> int:
        lens = 1
        cnt = 9
        start = 1
        while n > lens * cnt:
            n -= lens * cnt
            lens += 1
            cnt *= 10
            start *= 10
        start += (n - 1) / lens
        return int(str(start)[(n - 1) % lens])
