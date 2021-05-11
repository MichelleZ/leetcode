#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/parallel-courses-ii/
# Author: Miao Zhang
# Date:   2021-05-11

class Solution:
    def minNumberOfSemesters(self, n: int, dependencies: List[List[int]], k: int) -> int:
        preCourse = [0] * n
        for u, v in dependencies:
            preCourse[v-1] |= 1 << (u - 1)
        prereq = [0] * (1 << n)
        for state in range(1 << n):
            prereq[state] = 0
            for i in range(n):
                if (state >> i) & 1:
                    prereq[state] |= preCourse[i]
        dp = [float('inf') for _ in range(1 << n)]
        dp[0] = 0
        for state in range(1 << n):
            subset = state
            while subset >= 0:
                if bin(state).count('1') - bin(subset).count('1') <= k and ((subset & prereq[state]) == prereq[state]):
                    dp[state] = min(dp[state], dp[subset] + 1)
                if subset == 0: break
                subset = (subset - 1) & state
        return dp[(1 << n) - 1]
            
