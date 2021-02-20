#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/k-diff-pairs-in-an-array/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        counter = collections.Counter(nums)
        res = 0
        for n in set(nums):
            if k > 0 and n + k in counter:
                res += 1
            if k == 0 and counter[n] > 1:
                res += 1
        return res
