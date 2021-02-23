#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
# Author: Miao Zhang
# Date:   2021-02-23

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        i = 0
        j = n - 1
        t = sorted(nums)
        while i < n and nums[i] == t[i]: i += 1
        while j > i and nums[j] == t[j]: j -= 1
        return j - i + 1
