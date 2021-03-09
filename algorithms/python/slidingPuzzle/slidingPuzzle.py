#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sliding-puzzle/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        m = len(board)
        n = len(board[0])
        start = list()
        goal = list()
        for i in range(m):
            for j in range(n):
                start.append(board[i][j])
                goal.append((i * n + j + 1) % (m * n)) #123450
        if start == goal: return 0
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited = set()
        visited.add(tuple(start))
        steps = 0
        q = collections.deque()
        q.append(start)
        while q:
            steps += 1
            size = len(q)
            for _ in range(size):
                s = q.popleft()
                p = s.index(0)
                x = p // n
                y = p % n
                for d in dirs:
                    nx = x + d[0]
                    ny = y + d[1]
                    if nx < 0 or nx >= m or ny < 0 or ny >= n: continue
                    pp = nx * n + ny
                    t = s[:]
                    t[p], t[pp] = t[pp], t[p]
                    if tuple(t) in visited: continue
                    if t == goal: return steps
                    visited.add(tuple(t))
                    q.append(t)
        return -1
