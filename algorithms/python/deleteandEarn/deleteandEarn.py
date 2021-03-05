#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/delete-and-earn/
# Author: Miao Zhang
# Date:   2021-03-05

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cnt = collections.Counter(nums)
        prev = None
        avoid = 0
        using = 0
        for i in sorted(cnt):
            tmp = max(avoid, using)
            if i - 1 != prev:
                using = i * cnt[i] + max(avoid, using)
                avoid = tmp
            else:
                using = i * cnt[i] + avoid
                avoid = tmp
            prev = i
        return max(avoid, using)
