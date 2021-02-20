#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/beautiful-arrangement/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def countArrangement(self, n: int) -> int:
        self.res = 0
        visited = [0] * (n + 1)
        self.helper(n, visited, 1)
        return self.res
    
    def helper(self, n: int, visited: List[int], pos: int) -> None:
        if pos > n:
            self.res += 1
            return
        for i in range(1, n + 1):
            if visited[i] == 0 and (i % pos == 0 or pos % i == 0):
                visited[i] = 1
                self.helper(n, visited, pos + 1)
                visited[i] = 0
