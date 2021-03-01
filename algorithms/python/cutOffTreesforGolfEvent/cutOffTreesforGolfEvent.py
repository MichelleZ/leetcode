#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cut-off-trees-for-golf-event/
# Author: Miao Zhang
# Date:   2021-02-28

class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        m = len(forest)
        n = len(forest[0])
        # {height, x, y}
        trees = []
        for i in range(m):
            for j in range(n):
                if forest[i][j] > 1:
                    trees.append((forest[i][j], i, j))
        trees.sort()
        
        sx = 0
        sy = 0
        total_steps = 0
        for i in range(len(trees)):
            tx = trees[i][1]
            ty = trees[i][2]
            steps = self.bfs(forest, sx, sy, tx, ty)
            if steps == float('inf'): return -1
            forest[tx][ty] = 1
            total_steps += steps
            sx = tx
            sy = ty
        return total_steps
    
    def bfs(self, forest: List[List[int]], sx: int, sy: int, tx: int, ty: int) -> int:
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        visited = [[0 for _ in range(len(forest[0]))] for _ in range(len(forest))]
        q = collections.deque()
        q.append([sx, sy])
        steps = 0
        while q:
            n = len(q)
            for _ in range(n):
                cx, cy = q.popleft()
                if cx == tx and cy == ty:
                    return steps
                for d in dirs:
                    x = cx + d[0]
                    y = cy + d[1]
                    if x < 0 or x >= len(forest) or y < 0 or y >= len(forest[0]) or (not forest[x][y]) or visited[x][y]:
                        continue
                    visited[x][y] = 1
                    q.append([x, y])
            steps += 1
        return float('inf')
