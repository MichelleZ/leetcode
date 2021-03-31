#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-town-judge/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        degrees = [0] * (N + 1)
        for x, y in trust:
            degrees[x] -= 1
            degrees[y] += 1
        for i in range(1, N + 1):
            if degrees[i] == N - 1:
                return i
        return -1
