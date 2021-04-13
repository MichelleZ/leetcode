#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
# Author: Miao Zhang
# Date:   2021-04-13

class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        n = len(nums)
        res = [0, 0]
        for i in range(n):
            l = float('inf') if i == 0 else nums[i - 1]
            r = float('inf') if i == n - 1 else nums[i + 1]
            res[i % 2] += max(0, nums[i] - min(l, r) + 1)
        return min(res)
