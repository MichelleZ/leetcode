#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        cnt = 1
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                cnt -= 1
                if cnt < 0: return False
        if cnt == 0 and nums[0] < nums[n - 1]:
            return False
        return True
