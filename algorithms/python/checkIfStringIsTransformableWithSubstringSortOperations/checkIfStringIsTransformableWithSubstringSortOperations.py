#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/
# Author: Miao Zhang
# Date:   2021-05-18

class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        idx = defaultdict(deque)
        for i, c in enumerate(s):
            idx[int(c)].append(i)
        for c in t:
            if not idx[int(c)]:
                return False
            for i in range(int(c)):
                if idx[i] and idx[i][0] < idx[int(c)][0]:
                    return False
            idx[int(c)].popleft()
        return True
