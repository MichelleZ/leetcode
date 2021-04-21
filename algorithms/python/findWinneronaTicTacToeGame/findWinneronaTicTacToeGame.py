#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        grid = [['#' for _ in range(3)] for _ in range(3)]
        A = True
        for i, j in moves:
            grid[i][j] = 'A' if A else 'B'
            A = not A
        for i in range(3):
            for j in range(3):
                if grid[i][0] == grid[i][1] and grid[i][1] == grid[i][2] and grid[i][0] != "#":
                    return grid[i][0]
                if grid[0][i] == grid[1][i] and grid[1][i] == grid[2][i] and grid[0][i] != "#":
                    return grid[0][i]
        if grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2] and grid[0][0] != "#":
            return grid[0][0]
        if grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0] and grid[0][2] != "#":
            return grid[0][2]
        return "Draw" if len(moves) == 9 else "Pending"

