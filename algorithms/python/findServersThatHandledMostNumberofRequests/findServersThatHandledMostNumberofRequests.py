#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        from sortedcontainers import SortedList
        heap = []
        servers = SortedList(range(k))
        requests = [0] * k
        for i in range(len(arrival)):
            start = arrival[i]
            duration = load[i]
            while heap and heap[0][0] <= start:
                servers.add(heap[0][1])
                heapq.heappop(heap)
            if not servers: continue
            idx = servers.bisect_left(i % k)
            if idx == len(servers):
                idx = 0
            requests[servers[idx]] += 1
            heapq.heappush(heap, [start + duration, servers[idx]])
            servers.pop(idx)
        maxreq = max(requests)
        res  = []
        for i in range(k):
            if requests[i] == maxreq:
                res.append(i)
        return res

