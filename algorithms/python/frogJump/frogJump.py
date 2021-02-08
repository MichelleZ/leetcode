#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/frog-jump/
# Author: Miao Zhang
# Date:   2021-02-08

class Solution:
    def canCross(self, stones: List[int]) -> bool:
        from collections import defaultdict
        dic = defaultdict(bool)
        return self.dfs(stones, 0, 0, dic)
    
    def dfs(self, stones: List[int], pos: int, jump: int, dic: defaultdict) -> bool:
        n = len(stones)
        key = pos | jump << 11
        if pos >= n - 1: return True
        if key in dic: return dic[key]
        for i in range(pos + 1, n):
            dist = stones[i] - stones[pos]
            if dist < jump - 1: continue
            if dist > jump + 1: 
                dic[key] = False
                return dic[key]
            if self.dfs(stones, i, dist, dic): 
                dic[key] = True
                return dic[key]
        dic[key] = False
        return dic[key]
