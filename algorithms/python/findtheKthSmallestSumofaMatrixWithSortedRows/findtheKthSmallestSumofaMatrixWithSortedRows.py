#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        m = len(mat)
        n = len(mat[0])
        node = [0] * (m + 1)
        for i in range(m):
            node[0] += mat[i][0]
        heap = []
        seen = set()
        heapq.heappush(heap, node)
        seen.add(tuple(node))
        while heap:
            cur = heapq.heappop(heap)
            k -= 1
            if k == 0: return cur[0]
            for i in range(m):
                if cur[i + 1] == n - 1: continue
                nxt = cur[:]
                nxt[i + 1] += 1
                nxt[0] += mat[i][nxt[i + 1]] - mat[i][nxt[i + 1] - 1]
                if tuple(nxt) not in seen:
                    seen.add(tuple(nxt))
                    heapq.heappush(heap, nxt)
        return -1
