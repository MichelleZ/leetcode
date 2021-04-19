#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
# Author: Miao Zhang
# Date:   2021-04-19

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = []
        for i in range(len(startTime)):
            jobs.append([endTime[i], startTime[i], profit[i]])
        jobs.sort()
        dp = [0]
        dic = collections.defaultdict(int)
        dic[0] = 0
        for e, s, p in jobs:
            i = bisect.bisect_right(dp, s)
            p += dic[dp[i - 1]]
            if p > dic[dp[-1]]:
                dic[e] = p
                idx = bisect.bisect_right(dp, e)
                dp.insert(idx, e)
        return dic[dp[-1]]
