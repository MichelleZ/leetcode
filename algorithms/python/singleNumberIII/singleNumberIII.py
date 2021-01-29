#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/single-number-iii/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        res = 0
        for num in nums:
            res ^= num
        mask = 1
        while res & mask == 0:
            mask <<= 1
        num1 = 0
        num2 = 0
        for num in nums:
            if num & mask == 0:
                num1 ^= num
            else:
                num2 ^= num
        return [num1, num2]
