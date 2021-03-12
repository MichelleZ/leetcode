#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-array-with-same-average/
# Author: Miao Zhang
# Date:   2021-03-12

class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        n = len(nums)
        sums = sum(nums)
        nums.sort()
        for l in range(1, n // 2 + 1):
            if sums * l % n == 0 and self.dfs(nums, 0, l, sums * l // n):
                return True
        return False
    
    def dfs(self, nums: List[int], start: int, l: int, target: int) -> bool:
        if l == 0: return target == 0
        for i in range(start, len(nums) - l + 1):
            if i != start and nums[i] == nums[i - 1]: continue
            if self.dfs(nums, i + 1, l - 1, target - nums[i]): return True
        return False
