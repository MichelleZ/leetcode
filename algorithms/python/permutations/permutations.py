#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/permutations/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        if n == 0:
            return res
        if n == 1:
            return [nums]
        for i in range(n):
            subp = self.permute(nums[:i] + nums[i + 1:])
            for p in subp:
                res.append([nums[i]] + p)
        return res
