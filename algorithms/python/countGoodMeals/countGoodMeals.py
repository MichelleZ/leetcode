#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-good-meals/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        kMod = 10 ** 9 + 7
        powers = [1 << i for i in range(22)]
        m = collections.defaultdict(int)
        res = 0
        for d in deliciousness:
            for p in powers:
                if p - d in m:
                    res += m[p - d]
            m[d] += 1
        return res
