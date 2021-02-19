#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/relative-ranks/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        s = []
        for i in range(len(score)):
            s.append([score[i], i])
        s.sort(key = lambda x: x[0], reverse=True)
        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        res = [0] * len(s)
        for i in range(len(s)):
            res[s[i][1]] = medals[i] if i < 3 else str(i + 1)
        return res
