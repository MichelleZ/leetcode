#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-good-pairs/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        cnt = collections.defaultdict(int)
        res = 0
        for i in range(len(nums)):
            res += cnt[nums[i]]
            cnt[nums[i]] += 1
        return res
