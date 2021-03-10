#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/escape-the-ghosts/
# Author: Miao Zhang
# Date:   2021-03-10

# Manhattan Distance
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        steps = abs(target[0]) + abs(target[1])
        for g in ghosts:
            if abs(g[0] - target[0]) + abs(g[1] - target[1]) <= steps:
                return False
        return True
