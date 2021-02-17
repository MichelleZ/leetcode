#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/increasing-subsequences/
# Author: Miao Zhang
# Date:   2021-02-16

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = set()
        self.dfs(nums, 0, res, [])
        return map(list, res)
    
    def dfs(self, nums: List[int], pos: int, res: set, path: List[int]) -> None:
        if len(path) >= 2:
            res.add(tuple(path))
        for i in range(pos, len(nums)):
            if not path or nums[i] >= path[-1]:
                self.dfs(nums, i + 1, res, path + [nums[i]])
