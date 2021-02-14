#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
# Author: Miao Zhang
# Date:   2021-02-14

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        median = sorted(nums)[len(nums) // 2]
        return sum([abs(n - median) for n in nums])
