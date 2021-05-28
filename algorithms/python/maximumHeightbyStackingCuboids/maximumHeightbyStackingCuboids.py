#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        cuboids.append([0, 0, 0])
        n = len(cuboids)
        dp = [0] * n
        for c in cuboids: c.sort()
        cuboids.sort()
        for i in range(n):
            for j in range(i):
                if cuboids[i][0] >= cuboids[j][0] and cuboids[i][1] >= cuboids[j][1] and cuboids[i][2] >= cuboids[j][2]:
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2])
        return max(dp)
