#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/excel-sheet-column-number/
# Author: Miao Zhang
# Date:   2021-01-24

class Solution:
    def titleToNumber(self, s: str) -> int:
        res = 0
        for ss in s:
            res = res * 26 + ord(ss) - ord('A') + 1
        return res
