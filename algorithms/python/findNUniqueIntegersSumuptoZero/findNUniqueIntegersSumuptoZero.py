#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
# Author: Miao Zhang
# Date:   2021-04-22

class Solution:
    def sumZero(self, n: int) -> List[int]:
        res = []
        for i in range(1, n // 2 + 1):
            res.append(i)
            res.append(-i)
        if len(res) != n:
            res.append(0)
        return res
