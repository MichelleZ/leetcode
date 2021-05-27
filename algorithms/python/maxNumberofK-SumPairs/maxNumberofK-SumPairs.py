#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-number-of-k-sum-pairs/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        cnt = collections.Counter(nums)
        res = 0
        for num in nums:
            if cnt[num] < 1 or cnt[k - num] < 1 + (num + num == k):
                continue
            cnt[num] -= 1
            cnt[k - num] -= 1
            res += 1
        return res
