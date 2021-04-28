#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/create-target-array-in-the-given-order/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            res.insert(index[i], nums[i])
        return res
