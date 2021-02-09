#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/battleships-in-a-board/
# Author: Miao Zhang
# Date:   2021-02-09

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        '''
        the numbers of warships head
        if [i - 1, j] is 'X', [i, j] not head
        if [i, j - 1] is 'X', [i, j] not head
        '''
        cnt = 0
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'X':
                    if i > 0 and board[i - 1][j] == 'X':
                        continue
                    if j > 0 and board[i][j - 1] == 'X':
                        continue
                    cnt += 1
        return cnt
