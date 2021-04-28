#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cinema-seat-allocation/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        rows = collections.defaultdict(int)
        for i, j in reservedSeats:
            rows[i] |= 1 << (j - 1)
        res = (n - len(rows)) * 2
        for k, v in rows.items():
            left = v & 0b0111100000
            mid = v & 0b0001111000
            right = v & 0b0000011110
            if left == 0 and right == 0:
                res += 2
            elif left == 0 or right == 0 or mid == 0:
                res += 1
        return res
