#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-jumps-to-reach-home/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        kMaxPos = 6000
        if x == 0: return 0
        q = collections.deque()
        q.append([0, True])
        seen1 = set()
        seen2 = set()
        for f in forbidden:
            seen1.add(f)
            seen2.add(f)
        steps = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                cur, forward = q.popleft()
                if cur == x: return steps;
                if cur > kMaxPos: continue
                if cur + a not in seen1: 
                    seen1.add(cur + a)
                    q.append([cur + a, True])
                if cur - b >= 0 and forward and (cur - b) not in seen2:
                    seen2.add(cur - b)
                    q.append([cur - b, False])
            steps += 1
        return -1
