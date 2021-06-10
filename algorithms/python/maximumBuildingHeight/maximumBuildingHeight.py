#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-building-height/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        rs = restrictions
        rs.append([1, 0])
        rs.sort()
        if rs[-1][0] != n:
            rs.append([n, n - 1])
        m = len(rs)
        for i in range(1, m):
            rs[i][1] = min(rs[i][1], rs[i - 1][1] + rs[i][0] - rs[i - 1][0])
        for i in range(m - 2, -1, -1):
            rs[i][1] = min(rs[i][1], rs[i + 1][1] + rs[i + 1][0] - rs[i][0])
        
        res = 0
        for i in range(1, m):
            res = max(res, (rs[i][0] - rs[i - 1][0] + rs[i][1] + rs[i - 1][1]) // 2)
        return res
