#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-array-by-increasing-frequency/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        return sorted(nums, key = lambda x: (nums.count(x), -x))
