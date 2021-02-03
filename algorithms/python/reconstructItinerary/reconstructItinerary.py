#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reconstruct-itinerary/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        from collections import defaultdict
        trips = defaultdict(list)
        for i, j in tickets:
            trips[i].append(j)
        for i, j in trips.items():
            j.sort()
        res = []
        self.dfs(trips, "JFK", res)
        return reversed(res)
    
    def dfs(self, trips: defaultdict, src: str, res: List[str]):
        while trips[src]:
            dest = trips[src].pop(0)
            self.dfs(trips, dest, res)
        res.append(src)
