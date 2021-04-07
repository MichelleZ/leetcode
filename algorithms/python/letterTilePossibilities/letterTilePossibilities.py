#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/letter-tile-possibilities/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        if not tiles: return 0
        cnt = collections.Counter(tiles)
        self.res = 0
        self.dfs(cnt, "")
        return self.res

    def dfs(self, cnt: Counter, s: str) -> None:
        if s: self.res += 1
        for k, v in cnt.items():
            if v > 0:
                cnt[k] -= 1
                self.dfs(cnt, s + k)
                cnt[k] += 1
