#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/make-sum-divisible-by-p/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        remain = sum(nums) % p
        if remain == 0:
            return 0
        dic = {0: -1}
        res = len(nums)
        sums = 0
        for i, num in enumerate(nums):
            sums = (sums + num) % p
            orig = (sums + p - remain) % p
            if orig in dic:
                res = min(res, i - dic[orig])
            dic[sums] = i
        return res if res != len(nums) else -1

