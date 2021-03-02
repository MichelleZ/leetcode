#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/degree-of-an-array/
# Author: Miao Zhang
# Date:   2021-03-02

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        indices = collections.defaultdict(list)
        for i, n in enumerate(nums):
            indices[n].append(i)
        degree = 0
        for k, v in indices.items():
            degree = max(degree, len(v))
        res = len(nums)
        for k, v in indices.items():
            if len(v) != degree: continue
            res = min(res, v[-1] - v[0] + 1)
        return res
