#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-lines-to-write-string/
# Author: Miao Zhang
# Date:   2021-03-12

class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        lines = 1
        units = 0
        for c in s:
            if units + widths[ord(c) - ord('a')] > 100:
                lines += 1
                units = 0
            
            units += widths[ord(c) - ord('a')]
        return [lines, units]
