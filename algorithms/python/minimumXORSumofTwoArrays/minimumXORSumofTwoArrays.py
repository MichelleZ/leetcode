#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        dp = [float('inf') for _ in range(1 << n)]
        dp[0] = 0
        for mask in range(1, 1 << n):
            cnt = bin(mask).count('1')
            for i in range(n):
                dp[mask] = min(dp[mask], dp[mask ^ (1 << i)]+ (nums1[cnt - 1] ^ nums2[i]))
        return dp[(1 << n) - 1]
