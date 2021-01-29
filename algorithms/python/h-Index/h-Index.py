#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/h-index/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        citations.sort()
        res = 0
        for i in range(len(citations)):
            res = max(res, min(n - i, citations[i]))
        return res
