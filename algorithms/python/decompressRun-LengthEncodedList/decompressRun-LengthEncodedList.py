#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decompress-run-length-encoded-list/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(0, len(nums), 2):
            res += [nums[i + 1]] * nums[i]
        return res
