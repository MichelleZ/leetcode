#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-equal-frequency/
# Author: Miao Zhang
# Date:   2021-04-18

class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        cnt = [0] * 100001
        freq = [0] * 100001
        for n in nums:
            cnt[n] += 1
            freq[cnt[n]] += 1
        for i in range(len(nums) - 1, 0, -1):
            if cnt[nums[i]] * freq[cnt[nums[i]]] == i:
                return i + 1
            freq[cnt[nums[i]]] -= 1
            cnt[nums[i]] -= 1
            if cnt[nums[i - 1]] * freq[cnt[nums[i - 1]]] == i:
                return i + 1
        return 1
