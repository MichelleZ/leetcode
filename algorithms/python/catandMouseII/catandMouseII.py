#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cat-and-mouse-ii/
# Author: Miao Zhang
# Date:   2021-06-01

class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        m = len(grid)
        n = len(grid[0])
        memo = [[[[[0 for _ in range(3)] for _ in range(9)] for _ in range(9)] for _ in range(9)] for _ in range(9)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'F':
                    food = [i, j]
                if grid[i][j] == 'M':
                    mouse = [i, j]
                if grid[i][j] == 'C':
                    cat = [i, j]
        q = collections.deque()
        for i in range(m):
            for j in range(n):
                for t in range(1, 3):
                    if grid[i][j] == '#': continue
                    if i == food[0] and j == food[1]: continue
                    memo[i][j][food[0]][food[1]][t] = 2
                    memo[food[0]][food[1]][i][j][t] = 1
                    q.append([i, j, food[0], food[1], t])
                    q.append([food[0], food[1], i, j, t])
        for i in range(m):
            for j in range(n):
                for t in range(1, 3):
                    if grid[i][j] == '#': continue
                    memo[i][j][i][j][t] = 2
                    q.append([i, j, i, j, t])
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        
        def findAllAdjacents(mx, my, cx, cy, t):
            res = []
            if t == 1:
                for k in range(4):
                    for a in range(catJump + 1):
                        cx2 = cx + dirs[k][0] * a
                        cy2 = cy + dirs[k][1] * a
                        if cx2 < 0 or cx2 >= m or cy2 < 0 or cy2 >= n:
                            continue
                        if grid[cx2][cy2] == '#': break
                        res.append([mx, my, cx2, cy2, 2])
            if t == 2:
                for k in range(4):
                    for a in range(mouseJump + 1):
                        mx2 = mx + dirs[k][0] * a
                        my2 = my + dirs[k][1] * a
                        if mx2 < 0 or mx2 >= m or my2 < 0 or my2 >= n:
                            continue
                        if grid[mx2][my2] == '#': break
                        res.append([mx2, my2, cx, cy, 1])
            return res
        
        def allAdjacentsWin(mx, my, cx, cy, t):
            if t == 1:
                for k in range(4):
                    for a in range(mouseJump + 1):
                        mx2 = mx + dirs[k][0] * a;
                        my2 = my + dirs[k][1] * a;
                        if mx2 < 0 or mx2 >= m or my2 < 0 or my2 >= n:
                            continue
                        if grid[mx2][my2] == '#': break
                        if memo[mx2][my2][cx][cy][2] != 2:
                            return False
            if t == 2:
                for k in range(4):
                    for a in range(catJump + 1):
                        cx2 = cx + dirs[k][0] * a
                        cy2 = cy + dirs[k][1] * a
                        if cx2 < 0 or cx2 >= m or cy2 < 0 or cy2 >= n:
                            continue
                        if grid[cx2][cy2] == '#': break
                        if memo[mx][my][cx2][cy2][1] != 1:
                            return False
            return True
        
        steps = 0
        while q:
            steps += 1
            if steps > 2000: return False
            qlen = len(q)
            for _ in range(qlen):
                mx, my, cx, cy, t = q.popleft()
                status = memo[mx][my][cx][cy][t]
                for nxt in findAllAdjacents(mx, my, cx, cy, t):
                    mx2, my2, cx2, cy2, t2 = nxt
                    if memo[mx2][my2][cx2][cy2][t2]: continue
                    if t2 == status:
                        memo[mx2][my2][cx2][cy2][t2] = status
                        q.append([mx2, my2, cx2, cy2, t2])
                    elif allAdjacentsWin(mx2, my2, cx2, cy2, t2):
                        memo[mx2][my2][cx2][cy2][t2] = 2 if t2 == 1 else 1
                        q.append([mx2, my2, cx2, cy2, t2])
        return memo[mouse[0]][mouse[1]][cat[0]][cat[1]][1] == 1
                    
