#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bitwise-ors-of-subarrays/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        cur = set()
        res = set()
        for a in arr:
            cur = {a | b for b in cur} | {a}
            res |= cur
        return len(res)
