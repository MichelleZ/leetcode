#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/card-flipping-game/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        same = set()
        for i, v in enumerate(fronts):
            if v == backs[i]: same.add(v)
        res = float('inf')
        for v in itertools.chain(fronts, backs):
            if v not in same:
                res = min(res, v)
        return 0 if res == float('inf') else res
