#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-it-is-a-good-array/
# Author: Miao Zhang
# Date:   2021-04-19

class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        '''
        gcd(a, b) = d
        ax + by = td
        '''
        g = nums[0]
        for n in nums:
            g = math.gcd(g, n)
        return g == 1
