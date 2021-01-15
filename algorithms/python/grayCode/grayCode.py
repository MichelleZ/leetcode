#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/gray-code/
# Author: Miao Zhang
# Date:   2021-01-15

# n = 2
# 00 - 0
# 01 - 1
# 11 - 3
# 10 - 2
# '0' + sorted(n - 1) and '1' + reverse(n - 1) 
class Solution:
    def grayCode(self, n: int) -> List[int]:
        grays = dict()
        grays[0] = ['0']
        grays[1] = ['0', '1']
        for i in range(2, n + 1):
            igray = []
            for pre in grays[i - 1]:
                igray.append('0' + pre)
            for pre in grays[i - 1][::-1]:
                igray.append('1' + pre)
            gray[i] = igray
        return map(lambda x: int(x, 2), grays(n))
    
