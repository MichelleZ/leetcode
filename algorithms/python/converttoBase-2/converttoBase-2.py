#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/convert-to-base-2/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution(object):
    def baseNeg2(self, N):
        """
        :type N: int
        :rtype: str
        """
        res = ''
        while N:
            N, mod = -(N>>1), N % 2
            res = str(mod) + res
        return res if res else '0'
