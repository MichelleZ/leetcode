#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/previous-permutation-with-one-swap/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        n = len(arr)
        idx = -1
        maxval = 0
        for i in range(n - 1, 0, -1):
            if arr[i] >= arr[i - 1]: continue
            for j in range(i, n):
                if arr[j] < arr[i - 1] and maxval < arr[j]:
                    maxval = arr[j]
                    idx = j
            arr[i - 1], arr[idx] = arr[idx], arr[i - 1]
            break
        return arr
