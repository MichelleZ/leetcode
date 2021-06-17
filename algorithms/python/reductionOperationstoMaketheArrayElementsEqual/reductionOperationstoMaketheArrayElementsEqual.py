#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        res = 0
        cnt = 0
        for i in range(1, n):
            if nums[i] != nums[i - 1]:
                cnt += 1
            res += cnt
        return res
