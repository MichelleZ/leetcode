#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/combination-sum-ii/
# Author: Miao Zhang
# Date:   2021-01-08

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.res = []
        self.dfs(candidates, target, 0, [])
        return self.res
    
    def dfs(self, candidates: List[int], target: int, start: int, tmp: List[int]):
        if target == 0 and tmp not in self.res:
            self.res.append(tmp)
            return
        for i in range(start, len(candidates)):
            if target < candidates[i]:
                return
            self.dfs(candidates, target - candidates[i], i + 1, tmp + [candidates[i]])
