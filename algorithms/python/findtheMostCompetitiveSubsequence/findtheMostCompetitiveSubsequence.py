#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-most-competitive-subsequence/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        res = [0] * k
        j = 0
        for i in range(n):
            while j and res[j - 1] > nums[i] and j + n - i - 1 >= k:
                j -= 1
            if j < k:
                res[j] = nums[i]
                j += 1
        return res
