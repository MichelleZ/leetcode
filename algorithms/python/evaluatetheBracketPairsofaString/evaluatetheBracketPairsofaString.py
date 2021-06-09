#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        dic = {k: v for k, v in knowledge}
        res = []
        cur = ''
        going = False
        for c in s:
            if c == '(':
                going = True
            elif c == ')':
                going = False
                res.append(dic.get(cur, '?'))
                cur = ''
            elif going:
                cur += c
            else:
                res.append(c)
        return ''.join(res)
