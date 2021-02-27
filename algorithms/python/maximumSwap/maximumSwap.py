#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-swap/
# Author: Miao Zhang
# Date:   2021-02-27

class Solution:
    def maximumSwap(self, num: int) -> int:
        nums = [int(n) for n in str(num)]
        cnt = collections.defaultdict(int)
        for k, v in enumerate(nums):
            cnt[v] = k
        for i in range(len(nums) - 1):
            for n in range(9, nums[i], -1):
                if cnt[n] > i:
                    nums[i], nums[cnt[n]] = nums[cnt[n]], nums[i]
                    return int(''.join(str(n) for n in nums))
        return num
