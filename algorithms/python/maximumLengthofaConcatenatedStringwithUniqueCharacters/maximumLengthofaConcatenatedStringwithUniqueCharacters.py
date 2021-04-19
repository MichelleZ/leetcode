#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
# Author: Miao Zhang
# Date:   2021-04-19

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        setarr = []
        for a in arr:
            if len(set(a)) == len(a):
                setarr.append(set(a))
        
        self.res = 0
        def dfs(start, cur):
            self.res = max(self.res, len(cur))
            for i in range(start, len(setarr)):
                if not (cur & setarr[i]):
                    dfs(i + 1, cur | setarr[i])
        
        dfs(0, set())
        return self.res
