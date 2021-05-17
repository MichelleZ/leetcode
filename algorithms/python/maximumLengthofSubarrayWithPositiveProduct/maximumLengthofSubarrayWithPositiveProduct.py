#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        p = 0
        n = 0
        res = 0
        for x in nums:
            if x > 0:
                p += 1
                if n:
                    n += 1
            elif x < 0:
                tmp = p
                p = n + 1 if n else 0
                n = tmp + 1
            else:
                p = 0
                n = 0
            res = max(res, p)
        return res
