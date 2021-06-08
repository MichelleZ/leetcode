#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-center-of-star-graph/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        degrees = collections.defaultdict(int)
        for u, v in edges:
            degrees[u] += 1
            degrees[v] += 1
            if degrees[u] > 1: return u
            if degrees[v] > 1: return v
        return -1
