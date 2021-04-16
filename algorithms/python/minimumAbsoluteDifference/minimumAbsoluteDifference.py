#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-absolute-difference/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        res = []
        arr.sort()
        best = float('inf')
        for i in range(1, len(arr)):
            tmp = arr[i] - arr[i - 1]
            if tmp < best:
                best = tmp
                res.clear()
            if tmp == best:
                res.append([arr[i - 1], arr[i]])
        return res
