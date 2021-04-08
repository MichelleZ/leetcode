#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/car-pooling/
# Author: Miao Zhang
# Date:   2021-04-08

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        res = []
        for c, s, e in trips:
            res.append((s, c))
            res.append((e, -c))
        res.sort()
        for _, c in res:
            capacity -= c
            if capacity < 0: return False
        return True
