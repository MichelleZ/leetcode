#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/mini-parser/
# Author: Miao Zhang
# Date:   2021-02-06

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        def getNestedInteger(nums):
            if isinstance(nums, int):
                return NestedInteger(nums)
            res = NestedInteger()
            for num in nums:
                res.add(getNestedInteger(num))
            return res
        return getNestedInteger(eval(s))
