#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        delta = [0] * (2 * limit + 2)
        for i in range(n // 2):
            a = min(nums[i], nums[n - i - 1])
            b = max(nums[i], nums[n - i - 1])
            delta[a + 1] -= 1
            delta[a + b] -= 1
            delta[a + b + 1] += 1
            delta[b + limit + 1] += 1
        res = n
        cur = n
        for i in range(2, 2 * limit + 1):
            cur += delta[i]
            res = min(res, cur)
        return res
