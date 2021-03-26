#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/three-equal-parts/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        ones = sum(arr)
        if ones % 3 != 0: return [-1, -1]
        if ones == 0: return [0, len(arr) - 1]
        ones /= 3
        cnt = 0
        breaks = []
        for i, x in enumerate(arr):
            if x:
                cnt += x
                if cnt in [1, ones + 1, 2 * ones + 1]:
                    breaks.append(i)
                if cnt in [ones, 2 * ones, 3 * ones]:
                    breaks.append(i)
        i1, j1, i2, j2, i3, j3 = breaks
        if not(arr[i1: j1 + 1] == arr[i2: j2+1] == arr[i3:j3 + 1]):
            return [-1, -1]
        x = i2 - j1 - 1
        y  = i3 - j2 - 1
        z = len(arr) - j3 - 1
        if x < z or y < z: return [-1, -1]
        j1 += z
        j2 += z
        return [j1, j2 + 1]

