#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/course-schedule-iv/
# Author: Miao Zhang
# Date:   2021-05-08

class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        g = [[0 for _ in range(numCourses)] for _ in range(numCourses)]
        for p in prerequisites:
            g[p[0]][p[1]] = 1
        for k in range(numCourses):
            for i in range(numCourses):
                for j in range(numCourses):
                    g[i][j] |= g[i][k] & g[k][j]
        res = []
        for u, v in queries:
            res.append(g[u][v])
        return res
