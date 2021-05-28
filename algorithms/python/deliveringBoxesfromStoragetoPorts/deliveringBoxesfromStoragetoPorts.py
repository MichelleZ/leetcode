#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def boxDelivering(self, boxes: List[List[int]], portsCount: int, maxBoxes: int, maxWeight: int) -> int:
        n = len(boxes)
        dp = [0] * (n + 1)
        l = 0
        b = 0
        w = 0
        t = 1
        for r in range(n):
            if r == 0 or boxes[r][0] != boxes[r - 1][0]:
                t += 1
            w += boxes[r][1]
            while w > maxWeight or (r - l + 1) > maxBoxes or (l < r and dp[l + 1] == dp[l]):
                w -= boxes[l][1]
                l += 1
                if boxes[l][0] != boxes[l - 1][0]:
                    t -= 1
            dp[r + 1] = dp[l] + t
        return dp[n]
