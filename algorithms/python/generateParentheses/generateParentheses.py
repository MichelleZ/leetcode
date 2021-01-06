#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/generate-parentheses/
# Author: Miao Zhang
# Date:   2021-01-06

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def dfs(s, left, right):
            if len(s) == 2 * n:
                res.append(s)
                return
            if left < n:
                dfs(s + '(', left + 1, right)
            if right < left:
                dfs(s + ')', left, right + 1)
        dfs('', 0, 0)
        return res
