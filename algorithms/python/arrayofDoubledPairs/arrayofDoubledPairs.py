#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/array-of-doubled-pairs/
# Author: Miao Zhang
# Date:   2021-03-28

class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        cnt = collections.Counter(arr)
        for x in sorted(arr, key = abs):
            if cnt[x] == 0: continue
            if cnt[2 * x] == 0: return False
            cnt[x] -= 1
            cnt[2 * x] -= 1
        return True
