#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        n = len(arr)
        arr.sort()
        arr[0] = 1
        for i in range(1, n):
            arr[i] = min(arr[i], arr[i - 1] + 1)
        return arr[-1]
