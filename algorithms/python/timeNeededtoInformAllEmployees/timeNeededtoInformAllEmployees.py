#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/time-needed-to-inform-all-employees/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        cache = [-1] * n
        def dfs(cur):
            if cur == -1: return 0
            if cache[cur] == -1:
                cache[cur] = dfs(manager[cur]) + informTime[cur]
            return cache[cur]
        return max([dfs(i) for i in range(n)])
