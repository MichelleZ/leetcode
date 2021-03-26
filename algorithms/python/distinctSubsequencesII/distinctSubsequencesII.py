#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/distinct-subsequences-ii/
# Author: Miao Zhang
# Date:   2021-03-27

class Solution(object):
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        kMod = 10 ** 9 + 7
        dp = {}
        for c in S:
            dp[c] = (sum(dp.values()) + 1) % kMod
        return sum(dp.values()) % kMod
