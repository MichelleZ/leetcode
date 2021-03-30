#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-turbulent-subarray/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        up = [1 for _ in range(len(arr))]
        down = [1 for _ in range(len(arr))]
        res = 1
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                up[i] = down[i - 1] + 1
            if arr[i] < arr[i - 1]:
                down[i] = up[i - 1] + 1
            res = max(res, max(up[i], down[i]))
        return res
