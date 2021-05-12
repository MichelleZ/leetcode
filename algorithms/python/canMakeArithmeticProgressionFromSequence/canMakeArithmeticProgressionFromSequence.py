#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = arr[1] - arr[0]
        for i in range(2, len(arr)):
            if diff != arr[i] - arr[i - 1]:
                return False
        return True
