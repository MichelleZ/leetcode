#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        l = 1
        r = max(nums)

        def ops(m):
            res  = 0
            for x in nums:
                res += (x - 1) // m
            return res

        while l < r:
            m = l + (r - l) // 2
            cnt = ops(m)
            if cnt <= maxOperations:
                r = m
            else:
                l = m + 1
        return l
