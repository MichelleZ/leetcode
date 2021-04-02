#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        sums = sum(arr)
        if sums % 3 != 0:
            return False
        target = sums // 3
        i = 0
        cur = 0
        while i < len(arr):
            cur += arr[i]
            if cur == target:
                break
            i += 1
        if cur != target: return False
        j = i + 1
        while j + 1< len(arr):
            cur += arr[j]
            if cur == target * 2:
                return True
            j += 1
        return False
