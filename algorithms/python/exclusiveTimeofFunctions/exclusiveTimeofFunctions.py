#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/exclusive-time-of-functions/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0] * n
        stack = []
        prev = 0
        for log in logs:
            pid, ptype, time = log.split(':')
            if ptype == 'start':
                if stack:
                    res[stack[-1]] += int(time) - prev
                stack.append(int(pid))
                prev = int(time)
            else:
                res[stack.pop()] += int(time) - prev + 1
                prev = int(time) + 1
        return res
