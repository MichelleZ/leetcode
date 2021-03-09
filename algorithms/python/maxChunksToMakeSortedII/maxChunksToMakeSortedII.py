#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        counter = collections.defaultdict(int)
        counted = []
        for a in arr:
            counter[a] += 1
            counted.append((a, counter[a]))
        res = 0
        cur = tuple()
        for X, Y in zip(counted, sorted(counted)):
            cur = max(cur, X)
            if cur == Y: res += 1
        return res
