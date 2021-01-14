#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subsets/
# Author: Miao Zhang
# Date:   2021-01-14

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res =[[]]
        for num in nums:
            for tmp in res[:]:
                x = tmp[:]
                x.append(num)
                res.append(x)
        return res
