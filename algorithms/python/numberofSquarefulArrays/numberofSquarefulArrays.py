#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-squareful-arrays/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:
        A.sort()
        cur = []
        used = [0] * len(A)
        self.res = 0
        self.dfs(A, cur, used)
        return self.res

    def issquare(self, x: int, y: int) -> bool:
        s = int(sqrt(x + y))
        return s * s == x + y

    def dfs(self, A: List[int], cur: List[int], used: list[int]) -> None:
        if len(cur) == len(A):
            self.res += 1
            return
        for i in range(len(A)):
            if used[i]: continue
            if i > 0 and not used[i - 1] and A[i] == A[i - 1]:
                continue
            if cur and not self.issquare(cur[-1], A[i]):
                continue
            cur.append(A[i])
            used[i] = 1
            self.dfs(A, cur, used)
            used[i] = 0
            cur.pop()
