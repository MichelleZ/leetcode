#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-chunks-to-make-sorted/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        res = 0
        idx = 0
        for i in range(len(arr)):
            idx = max(idx, arr[i])
            if idx == i: res += 1
        return res
