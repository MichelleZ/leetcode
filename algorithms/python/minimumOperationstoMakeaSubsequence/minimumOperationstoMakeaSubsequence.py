#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        def LIS(a: List[int]) -> int:
            dp = []
            for x in a:
                if not dp or x > dp[-1]:
                    dp.append(x)
                else:
                    dp[bisect.bisect_left(dp, x)] = x
            return len(dp)
        
        m = {t: i for i, t in enumerate(target)}
        c = [m[a] for a in arr if a in m]
        return len(target) - LIS(c)
