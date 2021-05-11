#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/path-crossing/
# Author: Miao Zhang
# Date:   2021-05-11

class Solution:
    def isPathCrossing(self, path: str) -> bool:
        s = set()
        x = 0
        y = 0
        s.add(x * 10000 + y)
        for p in path:
            if p == 'N':
                y += 1
            elif p == 'S':
                y -= 1
            elif p == 'E':
                x += 1
            else:
                x -= 1
            if x * 10000 + y in s:
                return True
            s.add(x * 10000 + y)
        return False
