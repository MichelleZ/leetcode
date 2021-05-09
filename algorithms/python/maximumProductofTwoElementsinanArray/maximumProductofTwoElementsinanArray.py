#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
# Author: Miao Zhang
# Date:   2021-05-09

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        first = 0
        second = 0
        for n in nums:
            if n > first:
                second = first
                first = n
            elif n > second:
                second = n
        return (first - 1) * (second - 1)
