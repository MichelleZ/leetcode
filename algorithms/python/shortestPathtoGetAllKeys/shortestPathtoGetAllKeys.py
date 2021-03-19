#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-path-to-get-all-keys/
# Author: Miao Zhang
# Date:   2021-03-19

class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        all_keys = 0
        seen = [[[None] * 64 for _ in range(n)] for _ in range(m)]
        q = collections.deque()
        for i in range(m):
            for j in range(n):
                c = grid[i][j]
                if c == '@':
                    q.append((i << 16) | (j << 8))
                    seen[i][j][0] = 1
                elif c >= 'a' and c <= 'f':
                    all_keys |= (1 << (ord(c) - ord('a')))
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        steps = 0
        while q:
            size = len(q)
            for _ in range(size):
                s = q.popleft()
                i = s >> 16
                j = (s >> 8) & 0xFF
                keys = s & 0xFF
                if keys == all_keys: return steps
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    nkeys = keys
                    if x < 0 or x >= m or y < 0 or y >= n: continue
                    c = grid[x][y]
                    if c == '#': continue
                    if c in 'ABCDEF' and keys & (1 << (ord(c) - ord('A'))) == 0:
                        continue
                    if c in 'abcdef': 
                        nkeys |= (1 << (ord(c) - ord('a')))
                    if seen[x][y][nkeys]: continue
                    seen[x][y][nkeys] = 1
                    q.append((x << 16) | (y << 8) | nkeys)
            steps += 1
        return -1
