#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-recent-calls/
# Author: Miao Zhang
# Date:   2021-03-26

class RecentCounter:

    def __init__(self):
        self.q = collections.deque()

    def ping(self, t: int) -> int:
        while self.q and self.q[0] < t - 3000:
            self.q.popleft();
        self.q.append(t)
        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
