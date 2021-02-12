#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
# Author: Miao Zhang
# Date:   2021-02-12

###########################################################
# dp[x][delta] += dp[y][delta] + 1
###########################################################
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        from collections import defaultdict
        dp = [defaultdict(int) for _ in range(len(A))]
        res = 0
        for i in range(len(A)):
            for j in range(i):
                delta = A[i] - A[j]
                dp[i][delta] += 1
                if delta in dp[j]:
                    dp[i][delta] += dp[j][delta]
                    res += dp[j][delta]
        return res
