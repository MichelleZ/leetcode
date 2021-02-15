#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/total-hamming-distance/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        res = 0
        for i in range(32):
            cnt0 = 0
            cnt1 = 0
            mask = 1 << i
            for n in nums:
                if n & mask: cnt1 += 1
                else: cnt0 += 1
            res += cnt1 * cnt0
        return res
