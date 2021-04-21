#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-falling-path-sum-ii/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        m = len(arr)
        n = len(arr[0])
        for i in range(1, m):
            for j in range(0, n):
                x = float('inf')
                for k in range(0, n):
                    if k != j:
                        x = min(x, arr[i - 1][k])
                arr[i][j] += x
        return min(arr[m - 1])
            
