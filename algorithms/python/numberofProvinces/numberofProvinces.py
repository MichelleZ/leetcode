#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-provinces/
# Author: Miao Zhang
# Date:   2021-02-21

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(isConnected: List[List[int]], cur: int, n: int) -> None:
            for i in range(n):
                if isConnected[cur][i] == 1:
                    isConnected[cur][i] = isConnected[i][cur] = 0
                    dfs(isConnected, i, n)
        
        n = len(isConnected)
        res = 0
        for i in range(n):
            if isConnected[i][i] == 1:
                res += 1
                dfs(isConnected, i, n)
        return res
