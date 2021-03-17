#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-array-into-fibonacci-sequence/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        res = []

        def dfs(idx: int) -> bool:
            if len(S) == idx: return len(res) >= 3
            cur = 0
            for i in range(idx, len(S)):
                if i > idx and S[idx] == '0': break
                cur = cur * 10 + ord(S[i]) - ord('0')
                if cur > 2 ** 31 - 1: break
                if len(res) < 2 or cur == res[-2] + res[-1]:
                    res.append(cur)
                    if dfs(i + 1): return True
                    res.pop()
                elif len(res) > 2 and cur > res[-2] + res[-1]:
                    break
            return False

        dfs(0)
        return res
