#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stamping-the-sequence/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        res = []
        seen = [0 for _ in range(len(target))]
        total = 0
        stamplist = list(stamp)
        targetlist = list(target)
        while total < len(targetlist):
            found = False
            for i in range(len(targetlist) - len(stamplist) + 1):
                if seen[i] == 1: continue
                l = self.unStamp(stamplist, targetlist, i)
                if l == 0: continue
                seen[i] = 1
                total += l
                res.append(i)
                found = True
            if not found: return []
        res.reverse()
        return res

    def unStamp(self, stamp: List[str], target: list[str], start: int) -> int:
        l = len(stamp)
        for i in range(len(stamp)):
            if target[start + i] == '?':
                l -= 1
            elif target[start + i] != stamp[i]:
                return 0
        if l != 0:
            for i in range(len(target)):
                if start <= i < start + len(stamp):
                    target[i] = '?'
        return l
