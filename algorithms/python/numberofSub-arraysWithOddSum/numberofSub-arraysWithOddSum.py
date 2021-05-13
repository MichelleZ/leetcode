#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        res, odd, even = 0, 0, 0
        for x in arr:
            if x & 1:
                odd, even = even + 1, odd
            else:
                odd, even = odd, even + 1
            res += odd
        return int(res % (1e9+7))
