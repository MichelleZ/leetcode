#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-latest-group-of-size-m/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        length = [0] * (n + 2)
        cnt = [0] * (n + 2)
        res = -1
        for i in range(n):
            x = arr[i]
            l = length[x - 1]
            r = length[x + 1]
            t = 1 + l + r
            length[x - l] = length[x + r] = t;
            cnt[l] -= 1
            cnt[r] -= 1
            cnt[t] += 1
            if cnt[m]:
                res = i + 1
        return res
