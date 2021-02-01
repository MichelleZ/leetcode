#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/additive-number/
# Author: Miao Zhang
# Date:   2021-02-01

class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        return self.dfs(num, [])
    
    def dfs(self, num: str, path: List[int]) -> bool:
        if len(path) >= 3 and path[-1] != path[-2] + path[-3]:
            return False
        if not num and len(path) >= 3:
            return True
        for i in range(len(num)):
            cur = num[: i + 1]
            if cur[0] == '0' and len(cur) != 1: continue
            if self.dfs(num[i + 1:], path + [int(cur)]):
                return True
        return False
