#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-subarray-minimums/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        kMod = 10 ** 9 + 7
        stack = []
        res = 0
        dot = 0
        for j, y in enumerate(arr):
            cnt = 1
            while stack and stack[-1][0] >= y:
                x, c = stack.pop()
                cnt += c
                dot -= x * c
            stack.append((y, cnt))
            dot += y * cnt
            res += dot
        return res % kMod
