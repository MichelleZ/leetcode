#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/escape-a-large-maze/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        block = set()
        for b in blocked:
            block.add((b[0], b[1]))
        return self.dfs(source, target, source, block, set()) and \
               self.dfs(target, source, target, block, set())

    def dfs(self, source: List[int], target: List[int], cur: List[int], block: set, visited: set) -> bool:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        if cur == target:
            return True
        if abs(source[0] - cur[0]) + abs(source[1] - cur[1]) > 200:
            return True
        visited.add((cur[0], cur[1]))
        for d in dirs:
            x = cur[0] + d[0]
            y = cur[1] + d[1]
            if 0 <= x < 10 ** 6 and 0 <= y < 10 ** 6 and (x, y) not in visited and (x, y) not in block:
                if self.dfs(source, target, [x, y], block, visited):
                    return True
        return False

