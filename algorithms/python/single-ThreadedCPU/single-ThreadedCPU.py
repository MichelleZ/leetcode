#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/single-threaded-cpu/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        n = len(tasks)
        for i in range(n):
            tasks[i].append(i)
        tasks.sort()
        res = []
        heap = [] # processingtime, index
        i, cur = 0, 0
        while len(res) != n:
            if i < n and not heap and tasks[i][0] > cur:
                cur = tasks[i][0]
            while i < n and tasks[i][0] <= cur:
                heapq.heappush(heap, [tasks[i][1], tasks[i][2]])
                i += 1
            pro, idx = heapq.heappop(heap)
            cur += pro
            res.append(idx)
        return res

