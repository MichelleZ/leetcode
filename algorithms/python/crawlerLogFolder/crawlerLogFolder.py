#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/crawler-log-folder/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def minOperations(self, logs: List[str]) -> int:
        res = 0
        for log in logs:
            if log == '../':
                res = max(res - 1, 0)
            elif log != './':
                res += 1
        return res
