#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-number-of-nice-subarrays/
# Author: Miao Zhang
# Date:   2021-04-19

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        odd = [-1]
        for i in range(n):
            if nums[i] % 2 == 1:
                odd.append(i)
        odd.append(n)
        res = 0
        for i in range(1, len(odd) - k):
            res += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1])
        return res
