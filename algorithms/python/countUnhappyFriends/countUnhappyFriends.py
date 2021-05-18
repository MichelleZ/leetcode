#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-unhappy-friends/
# Author: Miao Zhang
# Date:   2021-05-18

class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        pair = [0 for _ in range(n)]
        for p1, p2 in pairs:
            pair[p1] = p2
            pair[p2] = p1
        prefer = [[0 for _ in range(n)] for _ in range(n)]
        for x in range(n):
            for i in range(len(preferences[x])):
                prefer[x][preferences[x][i]] = i
        res = 0
        for x in range(n):
            y = pair[x]
            found = False
            u = 0
            while u < n and not found:
                if u != x and u != y:
                    v = pair[u]
                    found |= (prefer[x][u] < prefer[x][y] and prefer[u][x] < prefer[u][v])
                u += 1
            if found:
                res += 1
        return res
