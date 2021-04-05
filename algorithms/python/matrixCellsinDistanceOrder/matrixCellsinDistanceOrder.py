#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/matrix-cells-in-distance-order/
# Author: Miao Zhang
# Date:   2021-04-05

class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        res = [(i, j) for i in range(R) for j in range(C)]
        res.sort(key=lambda x: abs(x[0] - r0) + abs(x[1] - c0))
        return res
