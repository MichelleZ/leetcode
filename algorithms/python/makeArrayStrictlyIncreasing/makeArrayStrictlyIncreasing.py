#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/make-array-strictly-increasing/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        m = len(arr1)
        arr2 = sorted(set(arr2))
        n = len(arr2)
        
        keep = [float('inf') for _ in range(m)]
        keep[0] = 0
        swap = [[float('inf') for _ in range(n)] for _ in range(m)]
        for j in range(0, n):
            swap[0][j] = 1
        
        for i in range(1, m):
            minkeep = float('inf')
            minswap = float('inf')
            for j in range(n):
                if j > 0: 
                    minswap = min(minswap, swap[i - 1][j - 1] + 1)
                if arr1[i] > arr2[j]:
                    minkeep = min(minkeep, swap[i - 1][j])
                if arr1[i] > arr1[i - 1]:
                    keep[i] = keep[i - 1]
                if arr2[j] > arr1[i - 1]:
                    swap[i][j] = keep[i - 1] + 1
                swap[i][j] = min(swap[i][j], minswap)
                keep[i] = min(keep[i], minkeep)
        s = min(swap[m - 1])
        k = keep[-1]
        res = min(s, k) 
        return -1 if res >= float('inf') else res
                    
