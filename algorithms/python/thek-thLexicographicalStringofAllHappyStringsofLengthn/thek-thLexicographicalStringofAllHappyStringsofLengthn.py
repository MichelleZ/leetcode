#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        self.res = ''

        def dfs(cur):
            nonlocal k
            if k <= 0:
                return
            if len(cur) == n:
                k -= 1
                if k == 0:
                    self.res = cur
                return
            for c in ['a', 'b', 'c']:
                if cur and cur[-1] == c:
                    continue
                dfs(cur + c)
        dfs('')
        return '' if k > 0 else self.res
