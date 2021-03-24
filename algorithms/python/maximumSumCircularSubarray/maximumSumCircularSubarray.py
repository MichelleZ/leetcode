#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-sum-circular-subarray/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        n = len(A)
        res = cur = float('-inf')
        # normal max sum
        for a in A:
            cur = a + max(cur, 0)
            res = max(res, cur)
        # 0            n-1
        # [...] + [....]
        rightsums = [None] * n
        rightsums[-1] = A[-1]
        for i in range(n - 2, -1, -1):
            rightsums[i] = rightsums[i + 1] + A[i]
        maxright = [None] * n
        maxright[-1] = rightsums[-1]
        for i in range(n - 2, -1, -1):
            maxright[i] = max(maxright[i + 1], rightsums[i])
        
        leftsum = 0
        for i in range(n - 2):
            leftsum += A[i]
            res = max(res, leftsum + maxright[i + 2])
        return res
