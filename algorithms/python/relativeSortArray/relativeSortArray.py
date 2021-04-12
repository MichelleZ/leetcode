#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/relative-sort-array/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        
        def cmp(x: int) -> (int, int):
            return (0, rank[x]) if x in rank else (1, x)
        
        rank = {x : i for i, x in enumerate(arr2)}
        arr1.sort(key=cmp)
        return arr1
