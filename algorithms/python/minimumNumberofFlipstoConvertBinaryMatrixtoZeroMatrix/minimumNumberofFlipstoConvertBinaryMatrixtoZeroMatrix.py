#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1), (0, 0)]
        
        def flip(s, i, j):
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n:
                    continue
                s ^= (1 << (x * n + y))
            return s
        
        steps = 0
        q = collections.deque()
        seen = [0 for _ in range(1 << (m * n))]
        start = 0
        for i in range(m):
            for j in range(n):
                start |= (mat[i][j] << (i * n + j))
        q.append(start)
        seen[start] = 1
        while q:
            lenq = len(q)
            for _ in range(lenq):
                s = q.popleft()
                if s == 0:
                    return steps
                for i in range(m):
                    for j in range(n):
                        t = flip(s, i, j)
                        if seen[t]: 
                            continue
                        seen[t] = 1
                        q.append(t)
            
            steps += 1
        return -1
