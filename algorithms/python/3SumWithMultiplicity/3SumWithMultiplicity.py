#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/3sum-with-multiplicity/
# Author: Miao Zhang
# Date:   2021-03-25

class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        kMod = 10 ** 9 + 7
        maxn = 100
        cnt = [0 for _ in range(maxn + 1)]
        for a in arr:
            cnt[a] += 1
        res = 0
        for i in range(target + 1):
            for j in range(i, target + 1):
                k = target - i - j
                if k < 0 or k >= len(cnt) or k < j: continue
                if not cnt[i] or not cnt[j] or not cnt[k]: continue
                if i == j == k:
                    res += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) // 6
                elif i == j and j != k:
                    res += cnt[i] * (cnt[i] - 1) // 2 * cnt[k]
                elif i != j and j == k:
                    res += cnt[i] * cnt[j] * (cnt[j] - 1) // 2
                else:
                    res += cnt[i] * cnt[j] * cnt[k]
        return res % kMod
