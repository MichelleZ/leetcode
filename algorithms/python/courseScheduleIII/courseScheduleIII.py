#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/course-schedule-iii/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        total = 0
        heap = []
        for t, d in courses:
            if total + t <= d:
                total += t
                heapq.heappush(heap, -t)
            elif heap and -heap[0] > t:
                total += t + heapq.heappop(heap)
                heapq.heappush(heap, -t)
        return len(heap)
