#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def splitString(self, s: str) -> bool:
        n = len(s)
        nums = []
        
        def dfs(start):
            if start == n: return len(nums) >= 2
            cur = 0
            i = start
            while i < n and cur < 1e11:
                cur = cur * 10 + int(s[i])
                if not nums or cur + 1 == nums[-1]:
                    nums.append(cur)
                    if dfs(i + 1): return True
                    nums.pop()
                if nums and cur >= nums[-1]: break;
                i += 1
            return False
        
        return dfs(0)
