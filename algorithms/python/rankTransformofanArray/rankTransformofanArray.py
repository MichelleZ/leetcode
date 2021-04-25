#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rank-transform-of-an-array/
# Author: Miao Zhang
# Date:   2021-04-24

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        s = sorted(list(set(arr)))
        m = collections.defaultdict(int)
        for i, v in enumerate(s):
            m[v] = i + 1
        res = []
        for a in arr:
            res.append(m[a])
        return res
