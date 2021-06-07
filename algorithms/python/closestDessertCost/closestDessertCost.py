#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/closest-dessert-cost/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        m = len(toppingCosts)
        mindiff = float('inf')
        res = float('inf')
        
        def dfs(s, cur):
            nonlocal mindiff, res, m
            if s == m:
                for bc in baseCosts:
                    total = bc + cur
                    diff = abs(total - target)
                    if diff < mindiff or (diff == mindiff and total < res):
                        mindiff = diff
                        res = total
                return
            for i in range(s, m):
                dfs(i + 1, cur)
                dfs(i + 1, cur + toppingCosts[i])
                dfs(i + 1, cur + toppingCosts[i] * 2)
        
        dfs(0, 0)
        return res
