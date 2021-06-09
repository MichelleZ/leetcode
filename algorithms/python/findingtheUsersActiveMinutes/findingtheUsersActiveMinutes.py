#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/finding-the-users-active-minutes/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        res = [0 for _ in range(k)]
        dic = collections.defaultdict(set)
        for i, time in logs:
            dic[i].add(time)
        for i in dic.values():
            cnt = len(i)
            if cnt <= k:
                res[cnt - 1] += 1
        return res
