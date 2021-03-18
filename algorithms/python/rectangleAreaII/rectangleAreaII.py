#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rectangle-area-ii/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        OPEN, CLOSE = 0, 1
        events = [] 
        for x1, y1, x2, y2 in rectangles:
            events.append((y1, OPEN, x1, x2))
            events.append((y2, CLOSE, x1, x2))
        events.sort()
        
        def query():
            x = 0
            cur = -1
            for x1, x2 in active:
                cur = max(cur, x1)
                x += max(0, x2 - cur)
                cur = max(cur, x2)
            return x
        
        active = []
        cur_y = events[0][0]
        res = 0
        for y, tye, x1, x2 in events:
            res += query() * (y - cur_y)
            if tye is OPEN:
                active.append((x1, x2))
                active.sort()
            else:
                active.remove((x1, x2))
            cur_y = y
        return res % (10 ** 9 + 7)
