#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-binary-string-after-change/
# Author: Miao Zhang
# Date:   2021-05-29

class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        n = len(binary)
        l = 0
        z = 0
        res = []
        for c in binary:
            if c == '0':
                z += 1
            elif z == 0:
                l += 1
            res.append('1')
        if l != n:
            res[l + z - 1] = '0'
        return ''.join(res)
