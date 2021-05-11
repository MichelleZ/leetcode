#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
# Author: Miao Zhang
# Date:   2021-05-11

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        kMod = 10 ** 9 + 7
        n = len(nums)
        cnt = [1] * (n + 1)
        for i in range(1, n + 1):
            cnt[i] = (cnt[i - 1] << 1) % kMod
        nums.sort()
        i = 0
        j = n - 1
        res = 0
        while i <= j:
            while i <= j and nums[i] + nums[j] > target:
                j -= 1
            if i > j: continue
            res = (res + cnt[j - i]) % kMod
            i += 1
        return res
