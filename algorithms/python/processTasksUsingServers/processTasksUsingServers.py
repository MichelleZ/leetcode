#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/process-tasks-using-servers/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        busy = list()
        idle = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(idle)
        
        ts = 0
        def release():
            while busy and busy[0][0] <= ts:
                _, idx = heapq.heappop(busy)
                heapq.heappush(idle, (servers[idx], idx))
        
        res = list()
        for i, task in enumerate(tasks):
            ts = max(ts, i)
            release()
            if not idle:
                ts = busy[0][0]
                release()
            _, idx = heapq.heappop(idle)
            res.append(idx)
            heapq.heappush(busy, (ts + task, idx))
        return res
