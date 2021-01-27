#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/combination-sum-iii/
# Author: Miao Zhang
# Date:   2021-01-27

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        nums = range(1, 10)
        self.dfs(nums, k, n, 0, [], res)
        return res;
    
    def dfs(self, nums: List[int], k: int, n: int, start: int, path: List[int],
            res: List[List[int]]) -> None:
        if k < 0 or n < 0:
            return
        if k == 0 and n == 0:
            res.append(path)
            return
