#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
# Author: Miao Zhang
# Date:   2021-05-26

class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        n = len(tasks)
        tasks.sort(key = lambda x: (x[1] - x[0]), reverse=True)
        res = 0
        actual = 0
        for act, threshold in tasks:
            res = max(res, actual + threshold)
            actual += act
        return res
