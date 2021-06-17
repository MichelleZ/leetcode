#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        n = len(chalk)
        remain = k % sum(chalk)
        for i in range(n):
            remain -= chalk[i]
            if remain < 0: return i
        return -1
