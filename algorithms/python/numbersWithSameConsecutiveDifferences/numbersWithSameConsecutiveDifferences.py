#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        q = collections.deque([i for i in range(1, 10)])
        if n == 1: q.appendleft(0)
        n -= 1
        while n > 0:
            size = len(q)
            for _ in range(size):
                num = q.popleft()
                r = num % 10
                if r + k <= 9:
                    q.append(num * 10 + r + k)
                if r - k >= 0 and k != 0:
                    q.append(num * 10 + r - k)
            n -= 1
        return list(q)
