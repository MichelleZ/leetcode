#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/friends-of-appropriate-ages/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        kMaxAge = 200;
        cnts = [0]  * (kMaxAge + 1)
        for age in ages: cnts[age] += 1
        res = 0
        for A, cntA in enumerate(cnts):
            for B, cntB in enumerate(cnts):
                if A * 0.5 + 7 >= B: continue
                if A < B: continue
                if A < 100 < B: continue
                res += cntA * cntB
                if A == B: res -= cntA
        return res
