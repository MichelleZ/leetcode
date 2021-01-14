#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/search-a-2d-matrix/
# Author: Miao Zhang
# Date:   2021-01-14

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        m = len(matrix)
        n = len(matrix[0])
        r = 0
        c = n - 1
        while True:
            if r < m and c >= 0:
                if matrix[r][c] == target:
                    return True
                elif matrix[r][c] > target:
                    c -= 1
                else:
                    r += 1
            else:
                return False
