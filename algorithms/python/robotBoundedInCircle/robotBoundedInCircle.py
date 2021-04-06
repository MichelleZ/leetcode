#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/robot-bounded-in-circle/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x = 0
        y = 0
        d = 0
        dx = [0, 1, 0, -1]
        dy = [-1, 0, 1, 0]
        for c in instructions:
            if c == 'G':
                x += dx[d]
                y += dy[d]
            elif c == 'L':
                d = (d - 1 + 4) % 4
            else:
                d = (d + 1) % 4
        return (x == 0 and y == 0) or d
