#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/least-operators-to-express-number/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        from functools import lru_cache
        cost = lambda i : i and i or 2
        @lru_cache(None)
        def dfs(target):
            i = math.floor(math.log(target, x))
            if x ** i == target : return cost(i)
            ans = cost(i) + dfs(target - x ** i) 
            if x ** (i+1) < 2 * target:
                ans = min(ans, dfs(x ** (i+1) - target) + i + 1)
            return ans 
        return dfs(target)-1
