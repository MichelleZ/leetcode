#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/queries-on-a-permutation-with-key/
# Author: Miao Zhang
# Date:   2021-04-30

class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        p = [(i + 1) for i in range(m)]
        res = []
        for q in queries:
            pos = -1
            for i in range(m):
                if p[i] == q:
                    pos = i
                    break
            res.append(pos)
            p.pop(pos)
            p.insert(0, q)
        return res
