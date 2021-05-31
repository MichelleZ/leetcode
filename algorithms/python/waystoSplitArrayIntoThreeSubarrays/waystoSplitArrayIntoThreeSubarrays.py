#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        kMod = 10 ** 9 + 7
        n = len(nums)
        for i in range(1, n):
            nums[i] += nums[i - 1]
        total = nums[-1]
        res = 0
        # [0, i],[i+1, j],[j+1, n-1]
        for i in range(n):
            idx1 = max(i + 1, bisect.bisect_left(nums, 2 * nums[i]))
            idx2 = min(n - 1, bisect.bisect_right(nums, nums[i] + (total - nums[i]) // 2))
            if idx2 <= idx1:
                continue
            res += idx2 - idx1
        return res % kMod
