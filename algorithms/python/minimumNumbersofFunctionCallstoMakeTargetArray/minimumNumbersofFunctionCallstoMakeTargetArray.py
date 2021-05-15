#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        return sum(bin(x).count('1') for x in nums) + len(bin(max(nums))) - 3
