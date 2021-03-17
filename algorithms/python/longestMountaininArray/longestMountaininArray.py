#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-mountain-in-array/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        inc = [0 for _ in range(len(arr))]
        dec = [0 for _ in range(len(arr))]
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                inc[i] = inc[i - 1] + 1
        for i in range(len(arr) - 2, -1, -1):
            if arr[i] > arr[i + 1]: 
                dec[i] = dec[i + 1] + 1
        res = 0
        for i in range(len(arr)):
            if inc[i] and dec[i]:
                res = max(res, inc[i] + dec[i] + 1)
        return res
