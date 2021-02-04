#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/russian-doll-envelopes/
# Author: Miao Zhang
# Date:   2021-02-04

from bisect import bisect_left
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = []
        for en in envelopes:
            idx = bisect_left(dp, en[1])
            if idx == len(dp):
                dp.append(en[1])
            else:
                dp[idx] = en[1]
        return len(dp)
