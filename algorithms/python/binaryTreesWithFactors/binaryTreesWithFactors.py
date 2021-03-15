#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-trees-with-factors/
# Author: Miao Zhang
# Date:   2021-03-15

###########################################################
# dp[c] = sum(dp[a]*dp[b]), c = a * b
# dp[i] = sum(dp[j] * dp[i/j])
###########################################################
class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        kMod = 10 ** 9 + 7
        arr.sort()
        dp = collections.defaultdict(int)
        for i in range(len(arr)):
            dp[arr[i]] = 1
            for j in range(i):
                if arr[i] % arr[j] == 0 and arr[i] // arr[j] in dp:
                    dp[arr[i]] += (dp[arr[j]] * dp[arr[i] // arr[j]]) % kMod
        res = 0
        for v in dp.values():
            res += v
        return res % kMod
