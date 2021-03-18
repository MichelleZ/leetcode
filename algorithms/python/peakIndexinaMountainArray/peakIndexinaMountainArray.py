#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/peak-index-in-a-mountain-array/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        return arr.index(max(arr))
