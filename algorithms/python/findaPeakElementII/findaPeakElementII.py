#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-a-peak-element-ii/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        l = 0
        r = m - 1

        def findMax(k):
            res = [k, 0]
            up = k - 1 if k - 1 >= 0 else k
            down = k + 1 if k + 1 < m else k
            for i in range(up, down + 1):
                for j in range(n):
                    if mat[res[0]][res[1]] < mat[i][j]:
                        res = [i, j]
            return res

        res = [0, 0]
        while l < r:
            mid = l + (r - l) // 2
            res = findMax(mid)
            if res[0] == mid:
                break
            elif res[0] < mid:
                r = mid - 1
            else:
                l = mid + 1
        return res

