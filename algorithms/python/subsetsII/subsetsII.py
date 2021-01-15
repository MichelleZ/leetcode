#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subsets-ii/
# Author: Miao Zhang
# Date:   2021-01-15

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for num in nums:
            for tmp in res[:]:
                x = tmp[:]
                x.append(num)
                if x not in res:
                    res.append(x)
        return res
