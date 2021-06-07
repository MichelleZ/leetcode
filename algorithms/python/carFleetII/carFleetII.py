#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/car-fleet-ii/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        def collide(i, j):
            return (cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1])
        
        n = len(cars)
        res = [-1] * n
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and (cars[i][1] <= cars[stack[-1]][1] or (
                             len(stack) > 1 and collide(i, stack[-1]) > res[stack[-1]])):
                stack.pop()
            res[i] = -1 if not stack else collide(i, stack[-1])
            stack.append(i)
        return res
