#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
# Author: Miao Zhang
# Date:   2021-05-08

#########################################################################
# dp[i][j]: 0--i, 0--j
# dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], max(0, dp[i - 1][j - 1]) + nums1[i] * nums2[j])
#########################################################################
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n1 = len(nums1)
        n2 = len(nums2)
        dp = [[float('-inf') for _ in range(n2 + 1)] for _ in range(n1 + 1)]
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], 
                               max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1])
        return dp[n1][n2]
