#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/integer-replacement/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def integerReplacement(self, n: int) -> int:
        '''
        01: -1
        11: +1
        '''
        res = 0
        while n > 1:
            res += 1
            if n & 1:
                if n & 2 and n != 3:
                    n += 1
                else:
                    n -= 1
            else:
                n >>= 1
        return res
