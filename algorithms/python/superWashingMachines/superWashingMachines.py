#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/super-washing-machines/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        sums = sum(machines)
        if sums % len(machines) != 0: return -1
        res = 0
        cnt = 0
        avg = sums // len(machines)
        for m in machines:
            cnt += m - avg
            res = max(res, max(abs(cnt), m - avg))
        return res
