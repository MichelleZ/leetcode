#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        kMod = 10 ** 9 + 7
        n = len(nums)
        cnt = [0] * n
        for s, e in requests:
            cnt[s] += 1
            if e + 1 < n:
                cnt[e + 1] -= 1
        for i in range(1, n):
            cnt[i] += cnt[i - 1]
        cnt.sort()
        nums.sort()
        res = 0
        for i in range(n):
            res += nums[i] * cnt[i]
        return res % kMod
