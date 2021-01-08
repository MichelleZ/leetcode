#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/combination-sum/
# Author: Miao Zhang
# Date:   2021-01-08

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.res = []
        self.dfs(candidates, target, 0, [])
        return self.res
    
    def dfs(self, candidates, target, start, tmp):
        '''
        start is used to repeat data retrieval process
        the other is to avoid like this situation [2, 2, 3] [3, 2, 2]
        '''
        if target == 0:
            return self.res.append(tmp)
        for i in range(start, len(candidates)):
            if target < candidates[i]:
                return
            self.dfs(candidates, target - candidates[i], i, tmp + [candidates[i]])
