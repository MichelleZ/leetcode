#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/string-compression-ii/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        n = len(s)
        
        @functools.lru_cache(maxsize=None)
        def dp(i, k):
            if k < 0: return n
            if i + k >= n: return 0
            res = dp(i + 1, k - 1)
            l = 0
            same = 0
            diff = 0
            j = i
            while j < n and diff <= k:
                if s[j] == s[i]:
                    same += 1
                    if same <= 2 or same == 10 or same == 100:
                        l += 1
                else:
                    diff += 1
                res = min(res, l + dp(j + 1, k - diff))
                j += 1
            return res
        
        return dp(0, k)
                    
