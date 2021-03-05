#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/daily-temperatures/
# Author: Miao Zhang
# Date:   2021-03-05

class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        stack = []
        res = [0 for _ in range(n)]
        for i in range(n - 1, -1, -1):
            while stack and T[stack[-1]] <= T[i]: stack.pop()
            res[i] = 0 if not stack else stack[-1] - i
            stack.append(i)
        return res
