#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/walking-robot-simulation/
# Author: Miao Zhang
# Date:   2021-03-20

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs = collections.defaultdict(set)
        for ox, oy in obstacles:
            obs[ox].add(oy)
        i, j = 0, 0
        dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        direction = 1
        res = 0
        for c in commands:
            if c == -2:
                direction = (direction - 1 + 4) % 4
            elif c == -1:
                direction = (direction + 1) % 4
            else:
                for _ in range(c):
                    x = i + dirs[direction][0]
                    y = j + dirs[direction][1]
                    if x in obs and y in obs[x]: break
                    i = x
                    j = y
                    res = max(res, i * i + j * j)
        return res
