#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
# Author: Miao Zhang
# Date:   2021-05-29

class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        p = []
        for i in range(len(nums)):
            if nums[i] == 1:
                p.append(i)
        sums = 0
        for i in range(k):
            sums += abs(p[i] - p[k // 2])
        res = sums
        for i in range(0, len(p) - k):
            mid = i + k // 2
            sums -= abs(p[mid] - p[i])
            sums += abs(p[i + k] - p[mid + 1])
            sums += k // 2 * (p[mid + 1] - p[mid])
            sums -= (k - 1 - k // 2) * (p[mid + 1] - p[mid])
            res = min(res, sums)
        offset = 0
        for i in range(k):
            offset += abs(i - k // 2)
        return int(res - offset)
