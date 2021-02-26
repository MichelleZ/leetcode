#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/robot-return-to-origin/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x = 0
        y = 0
        for m in moves:
            if m == 'U': y += 1
            elif m == 'D': y -= 1
            elif m == 'L': x -= 1
            elif m == 'R': x += 1
        return x == 0 and y == 0
