#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/unique-binary-search-trees/
# Author: Miao Zhang
# Date:   2021-01-16

# G(n) = f(1) + f(2) + f(3) .... + f(n)
# nums of root node which is 1 + nums of root node which is 2 + ... which is n
# G(n) = left * right = f(0) * f(n - 1) + f(1)f(n - 2) + f(3)f(n - 4)....
class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]
        dp[0], dp[1] = 1, 1
        for i in range(2, n + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - j - 1]
        return dp[n]
