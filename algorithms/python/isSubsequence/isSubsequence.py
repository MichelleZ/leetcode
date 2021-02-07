#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/is-subsequence/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        queue = collections.deque(s)
        for c in t:
            if not queue: return True
            if c == queue[0]:
                queue.popleft()
        return not queue
