#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-value-of-equation/
# Author: Miao Zhang
# Date:   2021-05-11

class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        q = collections.deque()
        res = float('-inf')
        for x, y in points:
            while q and x - q[0][1]> k:
                q.popleft()
            if q:
                res = max(res, x + y + q[0][0])
            while q and y - x >= q[-1][0]:
                q.pop()
            q.append([y - x, x])
        return res
