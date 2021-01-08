#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sudoku-solver/
# Author: Miao Zhang
# Date:   2021-01-08

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def isValid(x, y):
            val = board[x][y]
            board[x][y] = 'X'
            for i in range(9):
                if board[i][y] == val:
                    return False
            for j in range(9):
                if board[x][j] == val:
                    return False
            for i in range(3):
                for j in range(3):
                    if board[(x // 3) * 3 + i][(y // 3) * 3 + j] == val:
                        return False
            board[x][y] = val
            return True

        def dfs(board):
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for num in range(1, 10):
                            board[i][j] = str(num)
                            if isValid(i, j) and dfs(board):
                                return True
                            board[i][j] = '.'
                        return False
            return True

        dfs(board)

# Time Limit Exceeded
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        cell = [set() for _ in range(9)]
        
        # init env
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    row[i].add(board[i][j])
                    col[j].add(board[i][j])
                    cell[3 * (i // 3) + j // 3].add(board[i][j])
        
        def dfs(i, j):
            '''
            backtrace
            from left to right, from top to down
            i,j->i,j+1->i,8->i+1,0
            '''
            if board[i][j] != '.':
                if i == 8 and j == 8:
                    self.flag = True
                    return
                elif j < 8:
                    dfs(i, j + 1)
                else:
                    dfs(i + 1, 0)
            else:
                for num in range(10):
                    num = str(num)
                    if num not in row[i] and num not in col[j] and num not in cell[3 * (i // 3) + j // 3]:
                        board[i][j] = num
                        row[i].add(num)
                        col[j].add(num)
                        cell[3 * (i // 3) + j // 3].add(num)
                        if i == 8 and j == 8:
                            self.flag = True
                            return
                        elif j < 8:
                            dfs(i, j + 1)
                        else:
                            dfs(i + 1, 0)
                        if flag:
                            return
                        board[i][j] = '.'
                        row[i].remove(num)
                        col[j].remove(num)
                        cell[3 * (i // 3) + j // 3].remove(num)
        flag = False
        dfs(0, 0)
