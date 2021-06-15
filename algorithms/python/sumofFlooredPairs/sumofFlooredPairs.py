#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-floored-pairs/
# Author: Miao Zhang
# Date:   2021-06-15

class Solution:
    def sumOfFlooredPairs(self, nums: List[int]) -> int:
        kMod = 10 ** 9 + 7
        upper = max(nums)
        cnt = [0] * (upper + 1)
        for num in nums:
            cnt[num] += 1
        sums = [0] * (upper + 1)
        for i in range(1, upper + 1):
            sums[i] = sums[i - 1] + cnt[i]
        res = 0
        for y in range(1, upper + 1):
            if cnt[y]:
                d = 1
                while d * y <= upper:
                    res += cnt[y] * d * (sums[min((d + 1) * y - 1, upper)] - sums[d * y - 1])
                    d += 1
        return res % kMod
