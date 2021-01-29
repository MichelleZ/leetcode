#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/meeting-rooms-ii/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
	    from collections import heapq
		intervals.sort(key = lambda x: x[0})
        heap = []
		for it in intervals:
		if heap and it[0] >= heap[0]:
		    heapq.heapreplace(heap, it[2])
		else:
		    heapq.heappush(heap, it[2])
	    return len(heapq)

