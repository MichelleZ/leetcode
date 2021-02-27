#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/image-smoother/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        m = len(M)
        n = len(M[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1), (0, 0)]
        for i in range(m):
            for j in range(n):
                cnt = 0
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if 0 <= x < m and 0 <= y < n:
                        res[i][j] += M[x][y]
                        cnt += 1
                res[i][j] //= cnt
        return res
