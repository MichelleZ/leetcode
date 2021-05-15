#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        indegrees = [0] * n
        res = []
        for u, v in edges:
            indegrees[v] += 1
        for i in range(n):
            if indegrees[i] == 0:
                res.append(i)
        return res
