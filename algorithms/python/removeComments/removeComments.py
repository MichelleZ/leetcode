#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-comments/
# Author: Miao Zhang
# Date:   2021-03-04

class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        blocked = False
        res = []
        for line in source:
            i = 0
            if not blocked:
                newline = []
            while i < len(line):
                if line[i: i+2] == '/*' and not blocked:
                    blocked = True
                    i += 1
                elif line[i: i+2] == '*/' and blocked:
                    blocked = False
                    i += 1
                elif not blocked and line[i: i+2] == '//':
                    break
                elif not blocked:
                    newline.append(line[i])
                i += 1
            if newline and not blocked:
                res.append("".join(newline))
        return res
