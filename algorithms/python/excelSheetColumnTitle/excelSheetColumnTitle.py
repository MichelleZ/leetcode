#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/excel-sheet-column-title/
# Author: Miao Zhang
# Date:   2021-01-24

class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ''
        while n != 0:
            res = chr((n - 1) % 26 + 65) + res
            n = (n - 1) // 26
        return res
