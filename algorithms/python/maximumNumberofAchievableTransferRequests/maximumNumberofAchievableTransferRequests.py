#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        r = len(requests)
        for subset in range(r, 0, -1):
            for c in itertools.combinations(range(r), subset):
                degree = [0] * n
                for i in c:
                    degree[requests[i][0]] -= 1
                    degree[requests[i][1]] += 1
                if not any(degree):
                    return subset
        return 0
