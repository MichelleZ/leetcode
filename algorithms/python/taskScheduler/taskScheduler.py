#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/task-scheduler/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = collections.Counter(tasks)
        maxcnt = counter.most_common()[0][1]
        res = (maxcnt - 1) * (n + 1)
        res += len([i for i, val in counter.items() if val == maxcnt])
        return max(res, len(tasks))
