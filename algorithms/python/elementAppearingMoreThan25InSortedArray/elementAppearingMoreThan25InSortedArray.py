#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        t = len(arr) // 4
        for i in range(0, len(arr) - t):
            if arr[i] == arr[i + t]:
                return arr[i]
        return -1
