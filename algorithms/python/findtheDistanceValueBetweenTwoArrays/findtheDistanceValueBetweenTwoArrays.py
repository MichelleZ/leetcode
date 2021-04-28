#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        res = 0
        for a1 in arr1:
            flag = True
            for a2 in arr2:
                if abs(a1 - a2) <= d:
                    flag = False
                    break
            res += flag
        return res
