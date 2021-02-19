#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/next-greater-element-ii/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        res = [-1] * len(nums)
        stack = []
        for i in range(2 * len(nums)):
            while stack and nums[stack[-1]] < nums[i % len(nums)]:
                res[stack.pop()] = nums[i % len(nums)]
            stack.append(i % len(nums))
        return res
