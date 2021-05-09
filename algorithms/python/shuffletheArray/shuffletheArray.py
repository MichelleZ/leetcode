#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shuffle-the-array/
# Author: Miao Zhang
# Date:   2021-05-09

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        res = [0] * (2 * n)
        i = 0
        l = 0
        r = n
        while l < n:
            res[i] = nums[l]
            i += 1
            res[i] = nums[r]
            i += 1
            l += 1
            r += 1
        return res

