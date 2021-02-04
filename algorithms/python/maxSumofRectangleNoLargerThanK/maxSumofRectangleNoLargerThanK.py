#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
# Author: Miao Zhang
# Date:   2021-02-04

import bisect
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        if not matrix: return 0
        m = len(matrix)
        n = len(matrix[0])
        res = float('-inf')
        for l in range(n):
            print(f"l: {l}")
            sums = [0 for _ in range(m)]
            for r in range(l, n):
                print(f"r: {r}")
                for k in range(m):
                    sums[k] += matrix[k][r]
                prefix_sum = 0
                st = [0]
                for num in sums:
                    prefix_sum += num
                    tmp = prefix_sum - k
                    idx = bisect.bisect_left(st, tmp)
                    print(f"idx: {idx}, st: {st}, lenst: {len(st)}")
                    if idx < len(st):
                        res = max(res, prefix_sum - st[idx])
                    bisect.insort(st, prefix_sum)
                    print(st)
        return res
