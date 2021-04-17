#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        n = len(grid)
        def pos(x, y):
            return x * 100 + y
        
        def valid(x, y):
            return x >= 0 and x < n and y >= 0 and y < n and not grid[x][y]
        
        seen = set()
        q = collections.deque()
        q.append((pos(0, 0), pos(0, 1)))
        seen.add((pos(0, 0), pos(0, 1)))
        steps = 0
        while q:
            lenq = len(q)
            for _ in range(lenq):
                p = q.popleft()
                x1 = p[0] // 100
                y1 = p[0] % 100
                x2 = p[1] // 100
                y2 = p[1] % 100
                if x1 == n - 1 and y1 == n - 2 and x2 == n - 1 and y2 == n - 1:
                    return steps
                rotatedir = x1 == x2 # clockwise
                for i in range(3):
                    tx1 = x1
                    ty1 = y1
                    tx2 = x2
                    ty2 = y2
                    rx = x1
                    ry = y1
                    if i == 0: # down
                        tx1 += 1
                        tx2 += 1
                    elif i == 1: # right
                        ty1 += 1
                        ty2 += 1
                    else: # rotate
                        rx += 1
                        ry += 1
                        if rotatedir:
                            tx2 += 1
                            ty2 -= 1
                        else:
                            tx2 -= 1
                            ty2 += 1
                    if not valid(tx1, ty1) or not valid(tx2, ty2) or not valid(rx, ry) or (pos(tx1, ty1), pos(tx2, ty2)) in seen: continue
                    q.append((pos(tx1, ty1), pos(tx2, ty2)))
                    seen.add((pos(tx1, ty1), pos(tx2, ty2)))
            steps += 1
        return -1
