#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        x, y, z = target
        i, j, k = 0, 0, 0
        for tx, ty, tz in triplets:
            if tx <= x and ty <= y and tz <= z:
                i, j, k = max(i, tx), max(j, ty), max(k, tz)
        return (i, j, k) == (x, y, z)
