#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/duplicate-zeros/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        j = len(arr)
        while i < j:
            if arr[i] == 0:
                arr.insert(i,0)
                arr.pop()
                i += 2
            else:
                i += 1

class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        j = 0
        n = len(arr)
        while i < n:
            if arr[i] == 0:
                j += 1
            i += 1
            j += 1
        i -= 1
        j -= 1
        while i >= 0:
            if j < n:
                arr[j] = arr[i]
            if arr[i] == 0:
                j -= 1
                if j < n:
                    arr[j] = 0
            i -= 1
            j -= 1
