#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/goal-parser-interpretation/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def interpret(self, command: str) -> str:
        res = []
        for i, c in enumerate(command):
            if c == 'G':
                res.append('G')
            elif c == '(':
                if command[i + 1] == ')':
                    res.append('o')
                else:
                    res.append('al')
        return ''.join(res)
