#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-common-supersequence/
# Author: Miao Zhang
# Date:   2021-04-08

class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        l1 = len(str1)
        l2 = len(str2)
        dp = [[0 for _ in range(l2 + 1)] for _ in range(l1 + 1)]
        for i in range(1, l1 + 1):
            for j in range(1, l2 + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        s = ''
        while l1 or l2:
            c = ''
            if l1 == 0: 
                l2 -= 1
                c = str2[l2]
            elif l2 == 0:
                l1 -= 1
                c = str1[l1]
            elif str1[l1 - 1] == str2[l2 - 1]:
                l1 -= 1
                l2 -= 1
                c = str1[l1]
            elif dp[l1 - 1][l2] == dp[l1][l2]:
                l1 -= 1
                c = str1[l1]
            elif dp[l1][l2 - 1] == dp[l1][l2]:
                l2 -= 1
                c = str2[l2]
            s = c + s
        return s
