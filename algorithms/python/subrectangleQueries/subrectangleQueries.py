#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subrectangle-queries/
# Author: Miao Zhang
# Date:   2021-05-10

class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.grid = rectangle
        self.update = collections.deque()

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        self.update.appendleft([row1, col1, row2, col2, newValue])

    def getValue(self, row: int, col: int) -> int:
        for u in self.update:
            if row >= u[0] and row <= u[2] and col >= u[1] and col <= u[3]:
                return u[4]
        return self.grid[row][col]

# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)
