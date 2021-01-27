#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/the-skyline-problem/
# Author: Miao Zhang
# Date:   2021-01-27

import heapq
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        '''
        events = {{l, height: entering event},
                  {r, height: leaving event}}
        height[i] > height[i - 1] entering 
        right side leaving pop
        
        left side as entering event
        right side as leaving event
        -height as minheap 
        '''
        events = [(l, -h, r) for l, r, h in buildings]
        events += [(r, 0, 0) for r in set(i for _, i, _ in buildings)]
        events.sort()
        #  left, height
        res = [[0, 0]]
        # height, right
        heap = [(0, float('inf'))]
        for l, h, r in events:
            while heap[0][1] <= l:
                heapq.heappop(heap)
            if h:
                heapq.heappush(heap, (h, r))
            if res[-1][-1] != -heap[0][0]:
                res += [[l, -heap[0][0]]]
        return res[1:]
