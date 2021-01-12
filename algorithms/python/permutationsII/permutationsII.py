#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/permutations-ii/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        
        def dfs(nums, path):
            if not nums:
                res.append(path)
                return
            
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                dfs(nums[:i] + nums[i + 1:], path + [nums[i]])
        
        dfs(nums, [])
        return res
