#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/contiguous-array/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        sums = 0
        dic = dict()
        dic[0] = -1
        res = 0
        for i, num in enumerate(nums):
            if num == 0:
                sums -= 1
            else:
                sums += 1
            if sums in dic:
                res = max(res, i - dic[sums])
            else:
                dic[sums] = i
        return res
