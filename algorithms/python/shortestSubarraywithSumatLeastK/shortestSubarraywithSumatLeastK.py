#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
# Author: Miao Zhang
# Date:   2021-03-19

class Solution:
    def shortestSubarray(self, A: List[int], K: int) -> int:
        n = len(A)
        sums = [0]
        for i in A:
            sums.append(sums[-1] + i)
        res = n + 1
        q = collections.deque()
        for j, s in enumerate(sums):
            while q and s <= sums[q[-1]]:
                q.pop()
            while q and s - sums[q[0]] >= K:
                res = min(res, j - q.popleft())
            q.append(j)
        return res if res < n + 1 else -1
