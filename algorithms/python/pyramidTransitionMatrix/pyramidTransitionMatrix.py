#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pyramid-transition-matrix/
# Author: Miao Zhang
# Date:   2021-03-08

class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        dic = collections.defaultdict(list)
        for s in allowed:
            dic[s[0:2]].append(s[2])
        return self.dfs(bottom, '', dic)

    def dfs(self, cur: str, above: str, dic: dict) -> bool:
        if len(cur) == 2 and len(above) == 1: return True
        if len(above) == len(cur) - 1: return self.dfs(above, '', dic)
        pos = len(above)
        base = cur[pos: pos + 2]
        if base in dic:
            for c in dic[base]:
                if self.dfs(cur, above + c, dic): return True
        return False
