#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/defuse-the-bomb/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        res = [0] * n
        sign = 1 if k > 0 else -1
        for i in range(n):
            for j in range(1, abs(k) + 1):
                res[i] += code[(i + j * sign) % n]
        return res
