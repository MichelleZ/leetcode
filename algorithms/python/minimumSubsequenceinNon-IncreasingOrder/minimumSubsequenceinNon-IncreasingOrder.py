#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        total = sum(nums)
        res = []
        sums = 0
        for n in nums:
            sums += n
            res.append(n)
            if sums > total // 2: break
        return res
