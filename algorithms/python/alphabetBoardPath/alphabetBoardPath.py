#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/alphabet-board-path/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        paths = [['' for _ in range(26)] for _ in range(26)]
        for s in range(26):
            for t in range(26):
                dx = t // 5 - s // 5
                dy = t % 5 - s % 5
                path = ''
                while dx < 0:
                    path += 'U'
                    dx += 1
                while dy < 0:
                    path += 'L'
                    dy += 1
                while dx > 0:
                    path += 'D'
                    dx -= 1
                while dy > 0:
                    path += 'R'
                    dy -= 1
                paths[s][t] = path
        res = ''
        s = 'a'
        for c in target:
            res += paths[ord(s) - ord('a')][ord(c) - ord('a')] + '!'
            s = c
        return res
