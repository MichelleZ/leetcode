#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximize-distance-to-closest-person/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        n = len(seats)
        prev = -1
        res = 0
        for i in range(len(seats) + 1):
            if i == n:
                res = max(res, i - prev - 1)
            elif seats[i]:
                if prev == -1: 
                    res = i
                else:
                    res = max(res, (i - prev) // 2)
                prev = i
        return res
