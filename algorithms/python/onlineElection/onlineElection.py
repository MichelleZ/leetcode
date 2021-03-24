#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/online-election/
# Author: Miao Zhang
# Date:   2021-03-24

class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        self.leads = [[] for _ in range(len(times))]
        cnt = collections.Counter()
        last_lead = persons[0]
        for i, (t, p) in enumerate(zip(times, persons)):
            cnt[p] += 1
            if cnt[p] >= cnt[last_lead]:
                last_lead = p
            self.leads[i] = [t, last_lead]

    def q(self, t: int) -> int:
        return self.leads[bisect.bisect_right(self.leads, [t, float('inf')]) - 1][1]

