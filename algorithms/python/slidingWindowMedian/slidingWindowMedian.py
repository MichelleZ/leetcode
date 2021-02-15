#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sliding-window-median/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        if k == 0: return []
        res = []
        window = sorted(nums[0: k])
        for i in range(k, len(nums) + 1):
            res.append((window[k // 2] + window[(k - 1) // 2]) / 2.0)
            if i == len(nums): break
            idx = bisect.bisect_left(window, nums[i - k])
            window.pop(idx)
            bisect.insort_left(window, nums[i])
        return res
