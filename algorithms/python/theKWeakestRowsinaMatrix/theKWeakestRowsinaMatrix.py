#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat)
        sums = [sum(m) for m in mat]
        res = list(range(n))
        res.sort(key=lambda i: (sums[i], i))
        return res[:k]
