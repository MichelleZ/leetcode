#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/filling-bookcase-shelves/
# Author: Miao Zhang
# Date:   2021-04-09

class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        n = len(books)
        dp = [float('inf') for _ in range(n)]
        for i in range(n):
            h = 0
            w = 0
            for j in range(i, n):
                w += books[j][0]
                if w > shelf_width:
                    break
                h = max(h, books[j][1])
                dp[j] = min(dp[j], (0 if i == 0 else dp[i - 1]) + h)
        return dp[n - 1]
