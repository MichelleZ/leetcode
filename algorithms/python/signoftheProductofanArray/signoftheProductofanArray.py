#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sign-of-the-product-of-an-array/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def arraySign(self, nums: List[int]) -> int:
        res = 1
        for num in nums:
            if num == 0: return 0
            if num < 0: res = -res
        return res
