#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        self.res = 1
        n = len(s)
        seen = set()
        
        def dfs(start):
            if start == n:
                self.res = max(self.res, len(seen))
                return
            for i in range(start, n):
                ss = s[start: i + 1]
                if ss in seen: continue
                seen.add(ss)
                dfs(i + 1)
                seen.remove(ss)
        
        dfs(0)
        return self.res
