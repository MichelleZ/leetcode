#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/closest-room/
# Author: Miao Zhang
# Date:   2021-06-11

from sortedcontainers import SortedSet
class Solution:
    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        n = len(rooms)
        m = len(queries)
        for i in range(m):
            queries[i].append(i)
        queries.sort(key=lambda x: -x[1])
        rooms.sort(key=lambda x: -x[1])
        res = [-1] * m
        j = 0
        ids = SortedSet()
        for i, size, idx in queries:
            while j < n and rooms[j][1] >= size:
                ids.add(rooms[j][0])
                j += 1
            if not ids: continue
            idx1 = bisect.bisect_left(ids, i)
            i1 = float('inf')
            if idx1 != len(ids):
                i1 = ids[idx1]
            i2 = i1
            if idx1 != 0:
                i2 = ids[idx1 - 1]
            res[idx] = i1 if abs(i1 - i) < abs(i2 - i) else i2
        return res
