#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/132-pattern/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        third = float('-inf')
        stack = []
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] < third: return True
            while stack and nums[i] > stack[-1]:
                third = stack.pop()
            stack.append(nums[i])
        return False
