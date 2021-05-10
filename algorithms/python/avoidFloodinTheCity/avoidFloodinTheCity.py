#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/avoid-flood-in-the-city/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        res = [-1] * n
        full = collections.defaultdict(int)
        dry = []
        for i in range(n):
            lake = rains[i]
            if lake > 0:
                if lake in full:
                    idx = bisect.bisect_right(dry, full[lake])
                    if idx == len(dry):
                        return []
                    res[dry[idx]] = lake
                    dry.remove(dry[idx])
                full[lake] = i
            else:
                dry.append(i)
                res[i] = 1
        return res
