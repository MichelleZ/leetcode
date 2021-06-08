#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-score-of-a-good-subarray/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        i, j, m = k, k, nums[k]
        while True:
            res = max(res, m * (j - i + 1))
            if j - i + 1 == n: break
            l = nums[i - 1] if i else -1
            r = nums[j + 1] if j < n - 1 else -1
            if l >= r:
                i -= 1
                m = min(m, nums[i])
            else:
                j += 1
                m = min(m, nums[j])
        return res
