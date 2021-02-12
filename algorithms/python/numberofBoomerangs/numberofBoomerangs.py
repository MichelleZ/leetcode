#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-boomerangs/
# Author: Miao Zhang
# Date:   2021-02-12

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        def dis(p1: List[int], p2: List[int]) -> int:
            return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
        
        res = 0
        for i in points:
            record = {}
            for j in points:
                if i != j:
                    distance = dis(i, j)
                    record[distance] = record.get(distance, 0) + 1
            for val in record.values():
                if val >= 2:
                    res += (val - 1) * val
        return res
