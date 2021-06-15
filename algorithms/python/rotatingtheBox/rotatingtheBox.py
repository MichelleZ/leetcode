#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rotating-the-box/
# Author: Miao Zhang
# Date:   2021-06-15

class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m = len(box)
        n = len(box[0])
        for i in range(m):
            q = collections.deque()
            for j in range(n - 1, -1, -1):
                if box[i][j] == '*':
                    q.clear()
                elif box[i][j] == '#':
                    if q:
                        pos = q.popleft()
                        box[i][pos] = '#'
                        box[i][j] = '.'
                        q.append(j)
                else:
                    q.append(j)
        res = [["" for _ in range(m)] for _ in range(n)]
        for i in range(m):
            for j in range(n):
                res[j][m - 1 - i] = box[i][j]
        return res
