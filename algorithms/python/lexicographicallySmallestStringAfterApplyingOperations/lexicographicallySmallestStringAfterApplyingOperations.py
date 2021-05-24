#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        seen = set()
        self.res = list(s)
        def dfs(slist):
            if ''.join(slist) in seen:
                return
            seen.add(''.join(slist))
            self.res = min(self.res, slist)
            tmp = slist[:]
            for i in range(1, len(tmp), 2):
                tmp[i] = str((int(tmp[i]) + a) % 10)
            dfs(tmp)
            dfs(tmp[b: ] + tmp[0: b])
        dfs(list(s))
        return ''.join(self.res)
