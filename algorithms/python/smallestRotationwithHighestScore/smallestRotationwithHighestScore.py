#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-rotation-with-highest-score/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def bestRotation(self, A: List[int]) -> int:
        n = len(A)
        change = [0] * n
        for i in range(n):
            change[(i - A[i] + 1 + n) % n] -= 1
        for i in range(1, n):
            change[i] += change[i - 1] + 1
        return change.index(max(change))
