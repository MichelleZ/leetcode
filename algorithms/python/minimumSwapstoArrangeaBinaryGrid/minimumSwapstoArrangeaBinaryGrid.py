#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        zeros = []
        for row in grid:
            zero = 0
            i = n - 1
            while i >= 0 and row[i] == 0:
                zero += 1
                i -= 1
            zeros.append(zero)
        res = 0
        for i in range(n):
            j = i
            z = n - 1 - i
            while j < n and zeros[j] < z:
                j += 1
            if j == n: return -1
            while j > i:
                zeros[j] = zeros[j - 1]
                res += 1
                j -= 1
        return res
