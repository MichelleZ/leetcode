#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs[0])
        dp = [1 for _ in range(n)]
        for i in range(1, n):
            for j in range(i):
                valid = True
                for s in strs:
                    if s[j] > s[i]:
                        valid = False
                        break
                if valid:
                    dp[i] = max(dp[i], dp[j] + 1)
        return n - max(dp)
