#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pancake-sorting/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        res = []
        n = len(arr)
        while n > 0:
            idx = arr.index(max(arr[:n]))
            res.append(idx + 1)
            arr = arr[:idx + 1][::-1] + arr[idx+1:]
            res.append(n)
            arr = arr[:n][::-1]
            n -= 1
        return res
            
