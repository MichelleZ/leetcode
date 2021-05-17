#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        j = n - 1
        while j > 0 and arr[j - 1] <= arr[j]:
            j -= 1
        if j == 0: return 0
        res = j
        for i in range(n):
            if i > 0 and arr[i - 1] > arr[i]:
                break
            while j < n and arr[i] > arr[j]:
                j += 1
            res = min(res, j - i - 1)
        return res
