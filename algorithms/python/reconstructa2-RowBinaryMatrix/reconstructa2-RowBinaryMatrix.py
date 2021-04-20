#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        n = len(colsum)
        matrix = [[0 for _ in range(n)] for _ in range(2)]
        for j in range(n):
            if colsum[j] == 2:
                matrix[0][j] = 1
                matrix[1][j] = 1
                upper -= 1
                lower -= 1
        for j in range(n):
            if colsum[j] == 1:
                if upper > lower:
                    matrix[0][j] = 1
                    upper -= 1
                else:
                    matrix[1][j] = 1
                    lower -= 1
        if upper != 0 or lower != 0:
            return []
        return matrix
