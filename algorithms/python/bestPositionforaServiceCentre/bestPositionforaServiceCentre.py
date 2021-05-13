#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-position-for-a-service-centre/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        eps = 1e-7
        alpha = 1.0
        decay = 1e-3
        
        n = len(positions)
        batchSize = n
        x = sum(pos[0] for pos in positions) / n
        y = sum(pos[1] for pos in positions) / n
        
        getDist = lambda xc, yc: sum(((x - xc) ** 2 + (y - yc) ** 2) ** 0.5 for x, y in positions)
        
        while True:
            random.shuffle(positions)
            xPrev, yPrev = x, y
            for i in range(0, n, batchSize):
                j = min(i + batchSize, n)
                dx, dy = 0.0, 0.0
                for k in range(i, j):
                    pos = positions[k]
                    dx += (x - pos[0]) / (sqrt((x - pos[0]) ** 2 + (y - pos[1]) ** 2) + eps)
                    dy += (y - pos[1]) / (sqrt((x - pos[0]) ** 2 + (y - pos[1]) ** 2) + eps)
                
                x -= alpha * dx
                y -= alpha * dy
                alpha *= (1.0 - decay)
            
            if ((x - xPrev) ** 2 + (y - yPrev) ** 2) ** 0.5 < eps:
                break
                
        return getDist(x, y)
