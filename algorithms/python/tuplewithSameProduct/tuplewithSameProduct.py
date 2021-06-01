#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/tuple-with-same-product/
# Author: Miao Zhang
# Date:   2021-06-01

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        m = collections.defaultdict(int)
        for i in range(n):
            for j in range(i + 1, n):
                m[nums[i] * nums[j]] += 1
        res = 0
        for k, v in m.items():
            res += v * (v - 1) // 2
        return res * 8
