#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/keys-and-rooms/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set()
        self.dfs(rooms, 0, visited)
        return len(visited) == len(rooms)

    def dfs(self, rooms: List[List[int]], cur: int, visited: set) -> None:
        if cur in visited: return
        visited.add(cur)
        for nxt in rooms[cur]:
            self.dfs(rooms, nxt, visited)
